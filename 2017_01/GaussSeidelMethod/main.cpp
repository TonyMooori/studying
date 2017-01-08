#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;
 
template<int N>
bool is_converged(const float A[N][N],const float x[N],const float b[N],const float eps){
    float y[N];
    float norm1 = 0.0,norm2 = 0.0;
    
    REP(i,N){
        y[i] = 0.0;
        
        REP(j,N){
            y[i] += A[i][j]*x[j];
        }
        
        cout << "y[" << i << "]=\t" << y[i] << endl;
        
        y[i] -= b[i];
    }
    
    
    REP(i,N){
        norm1 += y[i]*y[i];
        norm2 += b[i]*b[i];
    }
    cout << (norm1 / norm2) << endl;
    return ( (norm1 / norm2) < eps);
}

template<int N>
void solve(const float A[N][N],float x[N],const float b[N],const float eps){
    while( is_converged<N>(A,x,b,eps) == false ){
    
        REP(i,N){
            float temp = b[i];
            
            REP(j,N){
                if( i == j )
                    continue;
                temp = temp - A[i][j]*x[j];
            }
            
            x[i] = temp / A[i][i];
        }
    }
    
    REP(i,N){
        REP(j,N){
            cout << A[i][j] << " ";
        }
        cout << x[i] << " "<< b[i] <<endl;
        
    }
}


int main(void){
    
    float A[3][3] = {10,2,3,2,10,4,3,4,10};
    float x[3] = {0,0,0};
    float b[3] = {2,5,4};
    
    REP(i,3){
        REP(j,3){
            cout << A[i][j] << " ";
        }
        cout << x[i] << " "<< b[i] <<endl;
        
    }
    solve<3>(A,x,b,1e-5);
    
    return 0;
}

