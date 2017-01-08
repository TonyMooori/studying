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

void solve1(const int n,const vector<int> a);
void solve2(const int n,const vector<int> a);

int main(void){
    
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i,n)cin >> a[i];
    
    solve1(n,a);
    solve2(n,a);
    
    return 0;
}

void solve2(const int n,const vector<int> a){
    int *dp;
    dp = (int*)malloc(n*sizeof(int));
    
    /*
    
    dp[i]は長さi+1の数列を作るときの最小の（数列の最後の数字）
    
    */
    REP(i,n)dp[i] = INF;
    
    REP(i,n){
        dp[0] = min( dp[0] , a[i] );
        REP(j,n-1){
            if( dp[j] < a[i] ){
                dp[j+1] = min(dp[j+1],a[i]);
            }else{
                break;
            }
        }
    }
    
    RREP(i,n){
        if( dp[i] != INF ){
            cout << i+1 << endl; 
            break;
        }
    }
    
    free(dp);
}

void solve1(const int n,const vector<int> a){
    int *dp = (int*)malloc((n)*sizeof(int));
    
    /*
    n 1e3
    a 1e6
    O(n^2)はセーフ
    
    dp[i]はa[i]を最後に使ったときの部分増加数列で最長の長さ
    */
    
    REP(i,n){
        dp[i] = 1;
        REP(j,i){
            if( a[j] < a[i] ){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    
    int max_len = 0;
    REP(i,n){
        max_len = max( dp[i] , max_len );
    }
    
    cout << max_len << endl;
    
    free(dp);
}