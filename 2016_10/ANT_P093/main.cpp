#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

using namespace std;
#define N_PRIME 1000000007
#define ll int64_t

#define N_VERTEX 1000

// 無効グラフ
bool mat[N_VERTEX][N_VERTEX];
// 頂点数
int n;

void clear_mat(){
    for(int i = 0 ; i < N_VERTEX ; i++ ){
        for(int j = 0 ; j < N_VERTEX ; j++ ){
            mat[i][j] = false;
        }
    }
}

void solve(){
    int color[n];
    
    for(int i = 0 ; i < n ; i++ ){
        color[i] = 0;
    }
    
    
    stack<int> search_vertex;
    
    for(int k = 0 ; k < n ; k++ ){
        if( color[k] == 0 ){
    
            color[k] = 1;
            search_vertex.push(k);
            
            while(search_vertex.size() > 0 ){
                int i = search_vertex.top();
                int c_here = color[i];
                int c_next = c_here == 1 ? 2 : 1;
                
                search_vertex.pop();
                
                //checked[i] = true;
                
                for(int j = 0 ; j < n ; j++ ){
                    if( mat[i][j] ){
                        if( color[j] == 0 ){
                            color[j] = c_next;
                            search_vertex.push(j);
                        }else if( color[j] == c_here ){
                            cout << "No" << endl;
                            return ;
                        }else if( color[j] == c_next ){
                            // pass
                        }
                    }
                }
            }
        }
    }
    
    cout << "Yes" << endl;
}

int main(void){
    clear_mat();
    n = 3;
    mat[0][1] = mat[1][0] = true;
    mat[0][2] = mat[2][0] = true;
    mat[1][2] = mat[2][1] = true;
    solve(); // No
    
    clear_mat();
    n = 4;
    mat[0][1] = mat[1][0] = true;
    mat[0][3] = mat[3][0] = true;
    mat[1][2] = mat[2][1] = true;
    mat[2][3] = mat[3][2] = true;
    solve(); // Yes
    
    return 0;
}
