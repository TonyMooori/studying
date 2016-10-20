#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

using namespace std;
#define N_PRIME 1000000007
#define ll int64_t

int main(void){
    int n,m;
    
    cin >> n >> m;
    
    int board[128][128];
    int sx,sy;
    int gx,gy;
    
    for(int y = 0 ; y < m ; y++ ){
        string s;
        cin >> s;
        for(int x = 0 ; x < n ; x++ ){
            int val;
            if( s[x] == '.' ){
                val = 0;
            }else if( s[x] == '#' ){
                val = 1;
            }else if( s[x] == 'S' ){    
                sx = x;
                sy = y;
                val = 0;
            }else if( s[x] == 'G' ){
                gx = x;
                gy = y;
                val = 0;
            }
            board[x][y] = val;
        }
    }
    
    queue<int> xs;
    queue<int> ys;
    queue<int> steps;
    
    xs.push(sx);
    ys.push(sy);
    steps.push(0);
    
    
    int min_step[n][m];
    for(int i = 0 ; i < n * m ; i++ )
        min_step[i%n][i/n] = 65536;
    
    while( xs.size() > 0 ){
        int x = xs.front();
        int y = ys.front();
        int step = steps.front();
        xs.pop();ys.pop();steps.pop();
        
        if( x < 0 || n <= x || y < 0 || m <= y ){
            continue;
        }
        
        if( min_step[x][y] < step )
            continue;
        
        min_step[x][y] = step;
        
        if( x ==gx && y == gy ){
            cout << step  << endl;
            break;
        }
        
        if( board[x][y] == 1 )
            continue;
        
        xs.push(x+1);
        ys.push(y+0);
        
        xs.push(x-1);
        ys.push(y+0);
        
        xs.push(x+0);
        ys.push(y+1);
        
        xs.push(x+0);
        ys.push(y-1);
        
        for(int i = 0 ; i < 4 ;i++ )
            steps.push(step+1);
    }
    
    return 0;
}
