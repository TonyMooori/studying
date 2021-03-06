using System;
using System.Drawing;


class Program
{
    const int N_COLOR = 8;
    
    static void SetColor(int n)
    {
        var color_cmd = new int[N_COLOR]{
            40,41,42,43,44,45,46,47
        };
        Console.Write("\x1b[{0}m",color_cmd[n]);
    }
    
    static void Main()
    {
        //SetColor(1);
        var img = new Bitmap("a.png");
        var W= 64;
        var H = 64;
        
        W*=2;
        var colors = new int[W,H,3];
        img = new Bitmap(img,new Size(W/2,H));
        
        var color_rgb = new int[N_COLOR,3]{
            {0,0,0},
            {128,0,0},
            {0,128,0},
            {238,255,240},
            {1,36,86},
            {255,237,255},
            {0,128,128},
            {192,192,192}
        };
        
        for(int x=0;x<W;x++){
            for(int y = 0; y <H ; y++ ){
                var c = img.GetPixel(x/2,y);
                colors[x,y,0] = c.R;
                colors[x,y,1] = c.G;
                colors[x,y,2] = c.B;
            }
        }
        
        for(int y=1;y<H-1;y++)
        {
            for(int x = 1; x <W-1; x++ )
            {
                var pix = new int[3,3];
                
                if( colors[x,y,0] >= 250 &&
                    colors[x,y,1] >= 250 &&
                    colors[x,y,2] >= 250 ){
                    Console.Write("\x1b[49m");
                    Console.Write(" ");
                    continue;
                }
                
                for(int c = 0 ; c < 3 ; c++ )
                {
                    int over;
                    
                    if( colors[x,y,c] >= 128 ){
                        over = colors[x,y,c]-128;
                        colors[x,y,c] = 128;
                    }else{
                        over = colors[x,y,c];
                        colors[x,y,c] = 0;
                    }
                        
                    colors[x+1,y+0,c] += over * 7 / 16;
                    colors[x-1,y+1,c] += over * 3 / 16;
                    colors[x+0,y+1,c] += over * 5 / 16;
                    colors[x+1,y+1,c] += over * 1 / 16;
                }
                
                int min_n=0;
                int min_dist=1<<16;
                
                for(int i = 0 ; i < N_COLOR ; i++ ){
                    int r = colors[x,y,0]-color_rgb[i,0];
                    int g = colors[x,y,1]-color_rgb[i,1];
                    int b = colors[x,y,2]-color_rgb[i,2];
                    int dist = r*r+g*g+b*b;
                    
                    if( dist < min_dist ){
                        min_dist = dist;
                        min_n = i;
                    }
                }
                SetColor(min_n);
                Console.Write(" ");
            }
            Console.Write("\x1b[49m");
            Console.Write("\n");
        }
        
        Console.WriteLine("test");
        
        Console.Write("\x1b[49m");
    }
}