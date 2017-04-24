#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>

#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;



template<typename T,int N>
void solve(const T M[N][N],T x[N],const T b[N]){
    // Solve linear system of equations Mx=b.
    // The result is assigned to x.
    // Refer to: http://slis.tsukuba.ac.jp/~fujisawa.makoto.fu/cgi-bin/wiki/index.php?LU%CA%AC%B2%F2
    
    T A[N][N];
    T temp;
    
    // copy matrix M to matrix A
    for(int i = 0 ; i < N ; i++ )
        for(int j = 0 ; j < N ; j++ )
            A[i][j] = M[i][j];
    /*
    // calculate L
    for(int i = 0 ; i < N ; i++ ){
        for(int j = 0 ; j <= i ; j++ ){
            temp = A[i][j];
            
        }
    }*/
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            T lu = A[i][j];
            for(int k = 0; k < j; k++){
                lu -= A[i][k]*A[k][j];    // l_ik * u_kj
            }
            A[i][j] = lu;
        }
 
        // u_ijの計算(i < j)
        for(int j = i+1; j < N; j++){
            T lu = A[i][j];
            for(int k = 0; k < i; k++){
                lu -= A[i][k]*A[k][j];    // l_ik * u_kj
            }
            A[i][j] = lu/A[i][i];
        }
    }
    
    for(int i = 0; i < N; i++){
        T bly = b[i];
        for(int j = 0; j < i; j++){
            bly -= A[i][j]*x[j];
        }
        x[i] = bly/A[i][i];
    }
 
    // 後退代入(back substitution)
    //  UX=YからXを計算
    for(int i = N-1; i >= 0; i--){
        T yux = x[i];
        for(int j = i+1; j < N; j++){
            yux -= A[i][j]*x[j];
        }
        x[i] = yux;
    }
}


int main(void){
    
    float A[3][3] = {1,2,3,8,9,4,7,6,5};
    float x[3] = {0,0,0};//3,5,7
    float b[3] = {34,97,86};
    
    solve<float,3>(A,x,b);
    REP(i,3){
        REP(j,3){
            printf(" %2.5f ",A[i][j]);
        }
        printf(" | %2.5f | %2.5f\n",x[i],b[i]);
    }
    
    return 0;
}

