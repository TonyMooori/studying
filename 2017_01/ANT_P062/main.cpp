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

void solve1(const int n,const int K,const int a[128],const int m[128]);
void solve2(const int n,const int K,const int a[128],const int m[128]);

int main(void){
    int n;
    int a[128],m[128];
    int K;
    cin >> n;
    REP(i,n)
        cin >> a[i];
    REP(i,n)
        cin >> m[i];
    cin >> K;
    
    /*
    数字 a[i] が m[i] 個ずつある
    これらのうち幾つかを選んでちょうどKにできるか
    */
    solve1(n,K,a,m);
    solve2(n,K,a,m);
    return 0;
}


void solve2(const int n,const int K,const int a[128],const int m[128]){
    /*
    n 1e2
    a 1e5
    m 1e5
    K 1e5
    
    0 <= j <= K
    dp[j] >= 0 なら作れる
    
    さいしょ
    dp[j] = -1
    dp[0] = 0 
    
    dp[j] は a[i]で使ってないやつの数
    なので
    dp[j] >= 0 なら dp[j] = m[i] (a[i]を使わずして作れるから)
    dp[j] < 0 (つくれない)とき
        j < a[i]
            dp[j] = -1
        j >= a[i]   // 使って作る(残っていれば)
            dp[j] = dp[ j - a[i] ] - 1;
    */
    int *dp;
    
    dp = (int*) malloc( (K+1) * sizeof( int ));
    memset(dp,-1,sizeof(int)*(K+1));
    dp[0] = 0;
    
    REP(i,n){
        REP(j,K+1){
            if( dp[j] >= 0 )
                dp[j] = m[i];
            else if( j < a[i] || dp[ j - a[i]] <= 0)
                dp[j] = -1;
            else
                dp[j] = dp[j - a[i]] - 1;
        }
    }
    
    if( dp[K] >= 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    free(dp);
}
void solve1(const int n,const int K,const int a[128],const int m[128]){
    /*
    n 1e2
    a 1e5
    m 1e5
    K 1e5
    
    dp[j] , 0 <= j <= K は作れたらtrue,作れなかったらfalse
    dp[0] は true
    それ以外はfalse
    */
    
    bool *dp;
    dp = (bool*) malloc ( (K+1) * sizeof(bool) );
    
    REP(i,K+1)
        dp[i] = false;
    dp[0] = true;
    
    REP(i,n){
        RREP(j,K+1){
            if( dp[j] ){
                FOR(k,1,m[i]+1){
                    if( j + k * a[i] >= K+1 )
                        break;
                    dp[ j + k * a[i] ] = true;
                }
            }
        }
    }
    
    if( dp[K] )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    
    free(dp);
}

