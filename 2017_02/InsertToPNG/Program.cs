using System;
using System.IO;
using System.Drawing;
using System.Text;
using System.Numerics;
using System.Collections.Generic;

class Program
{
    static void Main()
    {/*
        test();
        var t = BoolList.ToBoolArray(0x12);
        for(int i = 0 ; i < 8 ; i++ )
            Console.WriteLine(t[i]);
        
        
        var a = new BoolList();
        var b = new BoolList();
        a.Add(false);
        a.Add(false);
        a.Add(false);
        a.Add(true);
        b.Add(false);
        b.Add(true);
        
        Console.WriteLine(a.GetHashCode());
        Console.WriteLine(b.GetHashCode());
        Console.WriteLine(a==b);
        Console.WriteLine(a+b);
        
        var dict = new Dictionary<BoolList,int>();
        
        //dict.Add(a,1);
        //dict.Add(b,1);
        
        foreach(var k in dict.Keys)
            Console.WriteLine(dict[k]);
        
        return;
    */
        Console.WriteLine("1. zip");
        Console.WriteLine("2. unzip");
        
        var bdata = new BinaryData();
        var zip = new ZipData();
        var png = new PngData();
        
        
        if( int.Parse(Console.ReadLine()) == 1)
        {
            Console.WriteLine("Input original file path >>");
            
            // 情報源として読み取る
            bdata.Load(Console.ReadLine());
            // ハフマン符号化して読み取る
            zip.Load(bdata);
            // PNGデータとして読みとる
            png.Load(zip);
            
            Console.WriteLine("Input output file path >>");
            png.Save(Console.ReadLine());
        }
        else
        {
            Console.WriteLine("Input PNG file path >>");
            
            // PNGデータとして読みとる
            png.Load(Console.ReadLine());
            // ハフマン符号化して読み取る
            zip.Load(png);
            // 情報源として読み取る
            bdata.Load(zip);
            bdata.Save();
        }
    }
    
    static void test()
    {/*
        var pngt = new PngData();
        pngt.Load("te.png.png");
        var zipt = new ZipData();
        zipt.Load(pngt);
        var bdatat = new BinaryData();
        bdatat.Load(zipt);
        bdatat.Save("test.txt");
        */
        /*
        var bdata = new BinaryData();
        var bdata2 = new BinaryData();
        var zip = new ZipData();
        var zip2 = new ZipData();
        var png = new PngData();
        
        png.Load("a.png");
        png.Save("b.png");
        
        bdata.Load("Program.cs");
        zip.Load(bdata);
        png.Load(zip);
        png.Save("te.png");
        
        var png2 = new PngData();
        png2.Load("te.png.png");
        zip2.Load(png2);
        bdata2.Load(zip2);
        bdata2.Save("tat.txt");
        */
        
        
        //bdata.Save("a.txt");
        
        //Console.WriteLine(BitConverter.ToString(new byte[1]{0x01}));
    }
}

/*

元のファイル
→圧縮形式データ
→PNGデータ

PNGデータ
→圧縮形式データ
→元のデータ



 
*/