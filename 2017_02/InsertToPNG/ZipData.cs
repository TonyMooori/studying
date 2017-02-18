
using System;
using System.IO;
using System.Drawing;
using System.Text;
using System.Collections.Generic;
using System.Numerics;

using InfoSource = BoolList;

class ZipData
{
    // 元のバイト数．2バイトを1元とすると65,536……ふむ
    public const int n_byte = 2;
    // codeとバイトデータ
    public Dictionary<BoolList,InfoSource> Codes;
    // バイトデータとcode
    public Dictionary<InfoSource,BoolList> InvertedCodes;
    // バイトデータの総数
    public int byteNumber;
    // 符号化されたデータ
    public BoolList data;
    public string path;
    
    public ZipData()
    {
    }
    
    public void Load(BinaryData bdata)
    {
        // byte[]をkeyにすると全てユニークとして判定された
        var dict = new Dictionary< InfoSource , int >();
        this.path = bdata.path;
        
        for(int i = 0 ; i < bdata.GetNum(n_byte) ; i++ )
        {
            var element = new InfoSource(bdata.GetAt(i,n_byte));
            if( dict.ContainsKey( element ) )
                dict[element]++;
            else
                dict.Add(element,1);
        }
        
        var list = new List<Node>();
        
        // キーを列挙
        foreach (var k in dict.Keys)
        {
            var node = new Node();
            
            node.Value = dict[k];
            node.element = k;
            node.isLeaf = true;
            
            list.Add(node);
        }
        
        while(list.Count >= 2 )
        {
            // 小さい順
            // あとでpriority_queueに直す(直さないと思う)
            list.Sort( (a,b) => a.Value - b.Value );
            //Console.WriteLine(list[0].Value);
            //Console.WriteLine(list[1].Value);
            
            // 小さい順に取り出す
            var node1 = list[0];
            list.RemoveAt(0);
            var node2 = list[0];
            list.RemoveAt(0);
            
            // くっつける
            var node3 = new Node();
            node3.Value = node1.Value + node2.Value;
            node3.Left = node1;
            node3.Right = node2;
            
            // 加える
            list.Add(node3);
        }
        
        //Console.WriteLine(list[0].Value);
        
        // code,element
        this.Codes = new Dictionary<BoolList,InfoSource>();
        this.InvertedCodes  = new Dictionary<InfoSource,BoolList>();
        // 割当
        AssignCode(list[0],new BoolList());
        
        // なんか表示するやつ
        //foreach (var k in Codes.Keys)
        //    Console.WriteLine(Codes[k] +"\t" + dict[Codes[k]] +"\t" + k );
        
        // 総バイト数は保存しないと
        byteNumber = bdata.byteNumber;
        
        
        // エントロピーのでっかい情報源を作る
        data = new BoolList();
        for(int i = 0 ; i < bdata.GetNum(n_byte) ; i++ )
        {
            var element = new InfoSource(bdata.GetAt(i,n_byte));
            data.AddRange( InvertedCodes[element] );
        }
        
        // なんか表示するやつ
        //Console.WriteLine(data);
    }
    
    
    private void AssignCode(Node node,BoolList code)
    {
        if( node.isLeaf == true )
        {
            // 葉なら割り当てる
            Codes[code] = node.element;
            InvertedCodes[node.element] = code;
        }
        else
        {
            // 節ならこうする
            AssignCode(node.Left,code+true);
            AssignCode(node.Right,code+false);
        }
    }
    
    public void Load(PngData png)
    {
        var bytelist = new List<byte>(png.originalData.ToByteArray());
        var index = 0;
        byte[] temp_byte;
        
        temp_byte = bytelist.GetRange(index,4).ToArray();
        index += 4;
        if( temp_byte[0] != (byte)'P' )throw new Exception("P is error");
        if( temp_byte[1] != (byte)'D' )throw new Exception("D is error");
        if( temp_byte[2] != (byte)'C' )throw new Exception("C is error");
        if( temp_byte[3] != (byte)'A' )throw new Exception("A is error");
        
        temp_byte = bytelist.GetRange(index,4).ToArray();
        index += 4;
        if( BitConverter.ToInt32(temp_byte,0) != 1 ) throw new Exception("zip type error");
        
        temp_byte = bytelist.GetRange(index,4).ToArray();
        index += 4;
        if( ZipData.n_byte != BitConverter.ToInt32(temp_byte,0))throw new Exception("n_byte is error");
        
        // 元のファイルの文字列の長さ 4byte
        temp_byte = bytelist.GetRange(index,4).ToArray();
        index += 4;
        int path_bytes_Length = BitConverter.ToInt32(temp_byte,0);
        
        
        // 元のファイルの文字列データ path_bytes_Length byte
        this.path = Encoding.UTF8.GetString( bytelist.GetRange( index , path_bytes_Length ).ToArray() );
        index += path_bytes_Length;
        
        temp_byte = bytelist.GetRange(index,4).ToArray();
        index += 4;
        int Code_Count = BitConverter.ToInt32(temp_byte,0);
        
        temp_byte = bytelist.GetRange(index,4).ToArray();
        index += 4;
        this.byteNumber = BitConverter.ToInt32(temp_byte,0);
        
        this.Codes = new Dictionary<BoolList,InfoSource>();
        this.InvertedCodes  = new Dictionary<InfoSource,BoolList>();
        
        for(int i = 0 ; i < Code_Count ; i++ )
        {
            temp_byte = bytelist.GetRange(index,ZipData.n_byte).ToArray();
            index += ZipData.n_byte;
            
            var element = new InfoSource(temp_byte);
            
            temp_byte = bytelist.GetRange(index,4).ToArray();
            index += 4;
            
            var code_length = BitConverter.ToInt32(temp_byte,0);
            var code_byte_length = code_length / 8 + (code_length%8==0?0:1);
            
            temp_byte = bytelist.GetRange(index,code_byte_length).ToArray();
            index+=code_byte_length;
            
            var boollist_temp = new BoolList(temp_byte);
            var code = new BoolList();
            for(int j = 0 ; j < code_length ; j++ )
                code.Add( boollist_temp[j] );
                
            this.Codes[code] = element;
            this.InvertedCodes[element] = code;
        }
        
        temp_byte = bytelist.GetRange(index,4).ToArray();
        index += 4;
        int dataLength = BitConverter.ToInt32(temp_byte,0);
        
        temp_byte = bytelist.GetRange(index,dataLength/8 + (dataLength%8==0?0:1)).ToArray();
        index += dataLength/8 + (dataLength%8==0?0:1);
        
        var data_temp = new BoolList(temp_byte);
        this.data = new BoolList();
        for(int i = 0 ; i < dataLength ; i++ )
            this.data.Add( data_temp[i] );
    }
    
    
}


class Node
{
    public int Value;   // 出現回数
    public bool isLeaf; // 葉かどうか
    public InfoSource element; // 葉ならその元が入る
    public Node Left;   // 親なら子1が入る
    public Node Right;   // 親なら子2が入る
}