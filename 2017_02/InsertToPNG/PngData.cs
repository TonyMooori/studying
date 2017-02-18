
using System;
using System.IO;
using System.Drawing;
using System.Text;
using System.Numerics;
using System.Collections.Generic;

class PngData
{
    public BoolList originalData;
    
    public PngData()
    {
        originalData = new BoolList();
    }
    
    public void Load(string path)
    {
        var bmp = new Bitmap(path);
        originalData = new BoolList();
        
        for(int i = 0 ; i < bmp.Width ; i++ )
        {
            for(int j = 0 ; j < bmp.Height ; j++ )
            {
                var px = bmp.GetPixel(i,j);
                
                originalData.AddByte((byte)px.A);
                originalData.AddByte((byte)px.R);
                originalData.AddByte((byte)px.G);
                originalData.AddByte((byte)px.B);
                
            }
        }
        
    }
    
    public void Load(ZipData zip)
    {
        var bytelist = new List<byte>();
        
        // 最初の4byteはPDCA(とくに意味はない)
        bytelist.Add( (byte)'P' );    
        bytelist.Add( (byte)'D' );    
        bytelist.Add( (byte)'C' );    
        bytelist.Add( (byte)'A' );    
        
        // 圧縮形式(拡張予定はないけど) 4byte
        bytelist.AddRange( BitConverter.GetBytes((Int32)1) );
        
        // 何バイトで1バイトにしているか 4byte
        bytelist.AddRange( BitConverter.GetBytes((Int32)ZipData.n_byte) );
        
        // 元のファイルの文字列の長さ 4byte
        var path_bytes = Encoding.UTF8.GetBytes(zip.path);
        bytelist.AddRange( BitConverter.GetBytes((Int32)path_bytes.Length) );
        
        // 元のファイルの文字列データ path_bytes.Length byte
        bytelist.AddRange( path_bytes );
        
        // ハフマン符号の数(4byte)
        bytelist.AddRange( BitConverter.GetBytes((Int32)zip.Codes.Count));
        
        // 総バイト数(4byte)
        bytelist.AddRange( BitConverter.GetBytes((Int32)zip.byteNumber) );
        
        foreach(var code in zip.Codes.Keys )
        {
            var element = zip.Codes[code];
            
            // 元( n_byte byte )
            bytelist.AddRange( element.ToByteArray());
            // 符号の長さ( 4byte )
            bytelist.AddRange( BitConverter.GetBytes((Int32)code.Length) );
            // 符号( RoundUp( code.Length / 8.0 ) byte )
            bytelist.AddRange( code.ToByteArray() );
        }
        
        var data_bytes = zip.data.ToByteArray();
        
        // 符号化されたデータの総数 (4byte)
        bytelist.AddRange( BitConverter.GetBytes((Int32)zip.data.Length) );
        
        // 符号化されたデータ( data_bytes.Length byte )
        bytelist.AddRange( data_bytes );
        
        // 保存
        this.originalData = new BoolList(bytelist.ToArray());
    }
    
    public void Save(string path)
    {
        int n_pixel = (( originalData.Length / 8 ) / 4 );
        int side = CalcSide(n_pixel);
        
        var bmp = new Bitmap(side,side);
        var bytes = originalData.ToByteArray();
        
        int index = 0;
        for(int i = 0 ; i < bmp.Width ; i++ )
        {
            for(int j = 0 ; j < bmp.Height ; j++ )
            {
                int a = index < bytes.Length ? bytes[index] : 255;
                index++;
                int r = index < bytes.Length ? bytes[index] : 255;
                index++;
                int g = index < bytes.Length ? bytes[index] : 255;
                index++;
                int b = index < bytes.Length ? bytes[index] : 255;
                index++;
                
                bmp.SetPixel(i,j,Color.FromArgb(a,r,g,b));
                
            }
        }
        
        
        // 保存する
        bmp.Save(path ,System.Drawing.Imaging.ImageFormat.Png);
    }
    
    private int CalcSide(int n_pixel)
    {
        var sqrt = (int)(Math.Sqrt(n_pixel)+0.5);
        if( sqrt*sqrt == n_pixel )
            return sqrt;
        else
            return sqrt+1;
    }
}
