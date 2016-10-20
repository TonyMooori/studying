#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

using namespace std;
#define N_PRIME 1000000007
#define ll int64_t
const int INF = 1000000;
const int MAX_N = 128;
const int MAX_M = 128;
typedef pair<int,int> P;



char maxe[MAX_N][MAX_M+1]
int N,M;
int sx,sy;
int gx,gy;

int d[MAX_N][MAX_M]; // 最短距離格納

int dx[4] = { 0 , 1 , 0 , -1 };
int dy[4] = { 1 , 0 , -1 , 0 };

int bfs(){
    queue<P> que;
    for(int i = 0 ; i < N*M ; i++ )
        d[i%N][i/N] = iNF;
    
    que.push(P(sx,sy));
    d[sx][sy] = 0;
    
    while(que.size() > 0 ){
        P p = que.front();
        que.pop();
        
        if( que.first == gx && que.second == gy )
            break;
        
        for(int i = 0 ; i < 4 ; i++ ){  
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if( 0 <= nx && nx < N && 0 <= ny && ny < M && mae[nx][ny] != '#' && d[nx][ny] = INF ){
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    
    return d[gx][gy];
}

void solve(){
    int res = bfs();
    rintf("%d\n",res);
}