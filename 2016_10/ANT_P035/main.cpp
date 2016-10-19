//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t

/*-----------------------------------------------------*/

#define DOT 1
#define WATER 2

#define N_MAX 128

bool fill(int *board,int x,int y){
    if( board[x*N_MAX+y] == 0 )return false;
    else if( board[x*N_MAX+y] == DOT ) return false;
    
    board[x*N_MAX+y] = 0;
    for(int dx = -1 ; dx <= 1 ; dx++ )
        for(int dy = -1 ; dy <= 1 ; dy++ )
            fill(board,x+dx,y+dy);
    
    return true;
}

int main(void){
    int N,M;
    cin >> N >> M;
    int board[N_MAX*N_MAX] = {0};
    
    for(int i = 1 ; i <= N ; i++ ){
        string s;
        cin >> s;
        for(int j = 1 ; j <= M ; j++ ){
            board[i*N_MAX+j] = s[j-1] == '.' ? DOT : WATER;
        }
    }
    int count = 0;
    for(int i = 1 ; i <= N ; i++ ){
        for(int j = 1 ; j <= M ; j++ ){
            if( fill(board,i,j) )count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
