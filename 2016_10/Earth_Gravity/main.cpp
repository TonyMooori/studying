#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t

/* ---------------------------------------------

このコードはクソコードです，俗に言うスパゲティコード

とりあえず結果が見たかったのでめちゃくちゃ適当に書いてるので見ないほうが吉

ないようはNxNの格子を作って地球を微小に分割してそれぞれの講師に対して力を計算してる

もう一度いうがこれはクソコードなので見ないほうが良い

---------------------------------------------- */

#define N 100
int main(void){
    double pos[N][N][2];
    double force[N][N][2];
    bool is_earth[N][N] = {false};
    
    const double R = 6.0e+6;
    const double G = 6.67408e-11;
    const double dm = 1e3;  // 適当
    
    for(int i = 0 ; i < N ; i++ ){
        for(int j = 0 ; j < N ; j++ ){
            pos[i][j][0] = 4.0 * (((double)i) / N - 0.5 ) * R;
            pos[i][j][1] = 4.0 * (((double)j) / N - 0.5 ) * R;
            
            if( pos[i][j][0]*pos[i][j][0]+pos[i][j][1]*pos[i][j][1] <= R * R ){
                is_earth[i][j] = true;
            }
        }
    }
    
    for(int i = 0 ; i < N ; i++ ){
        for(int j = 0 ; j < N ; j++ ){
            force[i][j][0] = 0.0;
            force[i][j][1] = 0.0;
            for(int a = 0 ; a < N ; a++ ){
                for(int b = 0 ; b < N ; b++ ){
                    if( is_earth[a][b] && ( a != i || b != j ) ){
                        double dx = pos[i][j][0] - pos[a][b][0];
                        double dy = pos[i][j][1] - pos[a][b][1];
                        double rsq = dx*dx+dy*dy;
                        double f = G * dm * dm / rsq;
                        force[i][j][0] += f * dx;
                        force[i][j][1] += f * dy;
                    }
                }
            }
        }
    }
    
    cout << "X,Y,U,V" << endl;
    for(int i = 0 ; i < N * N ; i++ ){
        cout << pos[i/N][i%N][0] << ",";
        cout << pos[i/N][i%N][1] << ",";
        cout << force[i/N][i%N][0] << ",";
        cout << force[i/N][i%N][1] << endl;
    }
    
    return 0;
}
    
    
    
    