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

int main(void){
    int n,m;
    int dp[200][200];
    
    string s,t;
    cin >> n >> m;
    cin >> s >> t;
    
    REP(i,n+1)
        REP(j,m+1)
            dp[i][j] = 0;
    
    
    REP(i,n){
        REP(j,m){
            if( s[i] == t[j] ){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max( dp[i][j+1] , dp[i+1][j] );
            }
        }
    }
    
    cout << dp[n][m] << endl;
    
    return 0;
}

