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
    int n;
    int W;
    int *dp;
    
    cin >> n;
    vector<int> w(n),v(n);
    REP(i,n){
        cin >> w[i];
        cin >> v[i];
    }
    cin >> W;
    
    dp = (int*)malloc((W+1)*sizeof(int));
    
    REP(i,W+1)
        dp[i] = 0;
    
    REP(i,n){
        RFOR(j,0,W-w[i]+1){
            dp[j+w[i]] = max(v[i] + dp[j] , dp[j+w[i]]);
        }
    }
    
    int maxVal = -INF;
    REP(i,W+1)
        maxVal = max(maxVal,dp[i]);
    
    cout << maxVal << endl;
    
    free(dp);
    
    return 0;
}

