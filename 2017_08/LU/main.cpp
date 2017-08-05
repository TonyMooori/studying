#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>


#ifndef _USEFUL_MACROS_
#define _USEFUL_MACROS_
#define INF 99999999
#define N_PRIME 1000000007
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define OUTPUT_DEBUG
#ifdef OUTPUT_DEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x) do{}while(false)
#endif
#endif 

#define n 3

using namespace std;

int main(void){
    
    double a[n][n] = {
        {2,0,3},
        {2,1,0},
        {2,4,1}
    };
    double lu[n][n];
    
    
    REP(j,n){
        REP(i,j+1){
            lu[i][j]=a[i][j];
            
            REP(k,i)
                lu[i][j] -= lu[i][k]*lu[k][j];
        }
        
        FOR(i,j+1,n){
            lu[i][j] = a[i][j];
            
            REP(k,j)
                lu[i][j] -= lu[i][k]*lu[k][j];
                
            lu[i][j] /= lu[j][j];
        }
    }
    
    REP(i,n){
        REP(j,n){
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    
    
    REP(i,n){
        REP(j,n){
            cout << lu[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
