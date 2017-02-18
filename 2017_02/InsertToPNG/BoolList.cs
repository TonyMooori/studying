
using System;
using System.IO;
using System.Drawing;
using System.Text;
using System.Numerics;
using System.Collections.Generic;

class BoolList : IEquatable<BoolList>
{
    protected List<bool> data;
    public int Length { get { return data.Count; }}

    public bool this[int i]
    {
        set{ this.data[i] = value; }
        get{ return this.data[i]; }
    }
    
    public BoolList()
    {
        data = new List<bool>();
    }
    
    public BoolList(byte[] bytes)
    {
        data = new List<bool>();
        for(int i = 0 ; i < bytes.Length ; i++ )
            data.AddRange(BoolList.ToBoolArray(bytes[i]));
    }
    
    public static bool[] ToBoolArray(byte b)
    {
        // 0b 1000 0000
        byte temp = 0x80;
        var ret = new bool[8];
        
        for(int i = 0 ; i < 8 ; i++ )
        {
            ret[i] = (b & temp) != 0x00;
            temp >>= 1;
        }
        
        return ret;
    }
    
    public BoolList(BoolList other)
    {
        this.data = new List<bool>(other.data);
    }
    
    public override string ToString()
    {
        var ret = "";
        for(int i = 0 ; i < data.Count ; i++ )
            if( data[i] )
                ret += "1";
            else
                ret += "0";
        return ret;
    }
    
    public override int GetHashCode()
    {
        int ret = 0;
        
        for(int i = 0 ; i < data.Count ; i++ )
            if( data[i] )
                ret = ret ^ (1<<(i%32));
        
        return ret;
    }
    
    public void Add(bool flag)
    {
        data.Add(flag);
    }
    
    public void AddRange(BoolList other)
    {
        data.AddRange(other.data);
    }
    
    public void AddRange(bool[] ba)
    {
        data.AddRange(ba);
    }
    
    public void AddByte(byte b)
    {
        this.AddRange(BoolList.ToBoolArray(b));
    }
    
    public static BoolList operator+ (BoolList left,BoolList right)
    {
        var ret = new BoolList(left);
        ret.AddRange(right);
        return ret;
    }
    
    public static BoolList operator+ (BoolList left,bool flag)
    {
        var ret = new BoolList(left);
        ret.Add(flag);
        return ret;
    }
    
    public void Clear()
    {
        this.data.Clear();
    }
    
    public byte[] ToByteArray()
    {
        var ret = new byte[ Length / 8 + (Length%8==0?0:1)];
        
        for(int i = 0 ; i < ret.Length ; i++ )
        {
            byte b = 0x00;
            for(int j = 0 ; j < 8 ; j++ ){
                b <<= 1;
                
                var index = i * 8 + j;
                
                if(index<Length)
                    b |= data[ i * 8 + j ] ? (byte)0x01 : (byte)0x00; 
            }
            ret[i] = b;
        }
        
        return ret;
    }
    
    bool IEquatable<BoolList>.Equals(BoolList other)
    {
        if( other == null ) return false;
        if( other.Length != Length ) return false;
        
        for(int i = 0 ; i < Length ; i++ )
            if( other[i] != this.data[i] )
                return false;

        return true;
    }
    
    
    
}