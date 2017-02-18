
using System;
using System.IO;
using System.Drawing;
using System.Text;
using System.Numerics;
using System.Collections.Generic;

using InfoSource = BoolList;

class BinaryData
{
    private byte[] byteArray;
    // バイトデータの総数
    public int byteNumber{ get{ return byteArray.Length; }}
    public string path;
    
    public BinaryData()
    {
    }
    
    public void Load(string path)
    {
        // バイトデータ読み取り
        var fs = new FileStream(
            path,
            System.IO.FileMode.Open,
            System.IO.FileAccess.Read);
        this.byteArray = new byte[fs.Length];
        fs.Read(byteArray, 0, byteArray.Length);
        fs.Close();
        this.path = path;
    }
    
    public void Load(ZipData zip)
    {
        var code = new BoolList();
        var info = new InfoSource();
        this.path = zip.path;
        
        for(int i = 0 ; i < zip.data.Length ; i++ )
        {
            code.Add(zip.data[i]);
            
            if( zip.Codes.ContainsKey(code) )
            {
                // 一部分複合する．瞬時符号って最高
                info.AddRange( zip.Codes[code] );
                
                code.Clear();
            }
        }
        
        this.byteArray = new byte[zip.byteNumber];
        var temp = info.ToByteArray();
        
        for(int i = 0 ; i < this.byteArray.Length ; i++ )
            byteArray[i] = temp[i];
        /*
        for(int i = 0 ; i < byteArray.Length ; i++ )
        {
            byte b = 0x00;
            for(int j = 0 ; j < 8 ; j++ ){
                b <<= 1;
                b |= info[ i * 8 + j ] ? (byte)0x01 : (byte)0x00; 
            }
            byteArray[i] = b;
        }*/
    }
    
    public void Save()
    {
        // 保存する
        System.IO.FileStream fs = new FileStream(
            "saved_" + path,
            System.IO.FileMode.Create,
            System.IO.FileAccess.Write);
            
        fs.Write(byteArray, 0, byteArray.Length);
        fs.Close();
    }
    
    public byte[] GetAt(int at,int n_byte)
    {
        var ret = new byte[n_byte];
        
        for(int i = 0 ; i < n_byte ; i++ ){
            var index = i + at * n_byte;
            if( index >= byteArray.Length )
                ret[i] = (byte)0;
            else
                ret[i] = byteArray[index];
        }
        
        return ret;
    }
    
    public int GetNum(int n_byte)
    {
        var ret = this.byteNumber;
        if( ret % n_byte == 0 )
            return ret / n_byte;
        else
            return ret / n_byte + 1;
    }
}