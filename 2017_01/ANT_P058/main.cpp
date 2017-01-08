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
    int n,W;
    int dp[10000];
    vector<int> w,v;
    cin >> n;
    REP(i,n){
        w.push_back(0);
        v.push_back(0);
        cin >> w[i] >> v[i];
    }
    cin >> W;
    
    /*
    価値v[i],重さw[i]，何個でも選んでいい
    ※重さの合計がWを超えないように
    
    dp[j] ... 重さjを超えないような場合の最大の価値
    */
    
    REP(i,W+1)
        dp[i] = 0;
    
    REP(i,n){
        REP(j,W+1 - w[i]){
            dp[j+w[i]] = max( dp[j] + v[i] , dp[j+w[i]] );
        }
    }
    
    cout << dp[W] << endl;
    
    return 0;
}

