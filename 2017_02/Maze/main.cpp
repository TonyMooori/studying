#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>

#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;

#define W 15
#define H 81

void make_maze(bool maze[W][H]);
void solve_maze(bool maze[W][H]);

const int dx[4] = { 1, 0, -1, 0};
const int dy[4] = { 0, 1,  0,-1};

int main(void){
    bool maze[W][H];
    srand(time(NULL));
    make_maze(maze);
    
    REP(i,W){
        REP(j,H){
            cout << (maze[i][j]?'P':' ');
        }
        cout << endl;
    }
    
    solve_maze(maze);
    
    return 0;
}

void solve_maze(bool maze[W][H]){
    int cost[W][H];
    bool order[W][H];
    bool flag = true;
    stack<int> s;
    
    // 初期値マーックス
    REP(i,W)REP(j,H)cost[i][j] = INF;
    REP(i,W)REP(j,H)order[i][j] = false;
    
    cost[2][2] = 0;
    s.push(2*W+2);
    
    // costをぐわーって入れていってゴールつくまでやる
    while(s.size() > 0 && flag ){
        int temp = s.top();
        s.pop();
        
        int x = temp % W;
        int y = temp / W;
        
        REP(i,4){
            if( maze[x+dx[i]][y+dy[i]] ){
                continue;
            }else{
                if( cost[x+dx[i]][y+dy[i]] > cost[x][y]+1 ){
                    cost[x+dx[i]][y+dy[i]] = cost[x][y]+1;
                    s.push((y+dy[i])*W+x+dx[i]);
                    if( x+dx[i] == W-3 && y+dy[i] == H - 3 ){
                        flag = true;
                        break;
                    }
                }
            }
        }
    }
    
    int x = W-3;
    int y = H-3;
    // 逆にたどる
    do{
        order[x][y] = true;
        REP(i,4){
            if( cost[x][y] == cost[x+dx[i]][y+dy[i]] +1 ){
                x = x + dx[i];
                y = y + dy[i];
                break;
            }
        }
    }while( (x == 2 && y == 2 ) == false );
    
    
    REP(i,W){
        REP(j,H){
            cout << (order[i][j]?'A':(maze[i][j]?'P':' '));
        }
        cout << endl;
    }
    
}

void make_maze(bool maze[W][H]){
    // 外周を道路にする
    REP(i,W){
        REP(j,H){
            maze[i][j] = true;
        }
        maze[i][0] = false;
        maze[i][H-1] = false;
    }
    
    REP(i,H){
        maze[0][i] = false;
        maze[W-1][i] = false;
    }
    
    // 移動先の候補用
    bool movable[W][H];
    REP(i,W)REP(j,H)movable[i][j] = false;
    
    FOR(i,1,W-2)
        FOR(j,1,H-2)
            if( i%2 == 0 && j%2 == 0 )
                movable[i][j] = true;
    
    int x,y;
    x = 2;
    y = 2;
    maze[x][y] = false;
    
    while(true){
        // 行ける向き一覧を作る
        vector<int> ok;
        REP(i,4){
            if( maze[x+dx[i]*2][y+dy[i]*2] 
             && maze[x+dx[i]][y+dy[i]] )
                ok.push_back(i);
        }
        
        if( ok.size() == 0 ){
            // 動けなかったら別の道へ移動
            bool flag = true;
            movable[x][y] = false;
            
            // 次の場所へ
            FOR(i,1,W-1){
                FOR(j,1,H-1){
                    if( movable[i][j] && (maze[i][j] == false) ){
                        x = i;
                        y = j;
                        flag = false;
                        break;
                    }
                }
            }
            
            if( flag )
                break;
        }else{
            // ランダムに移動
            int index = ok[ rand() % ok.size() ];
            
            maze[x+dx[index]*1][y+dy[index]*1] = false;
            maze[x+dx[index]*2][y+dy[index]*2] = false;
            x = x+dx[index]*2;
            y = y+dy[index]*2;
        }
    }
}
