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
    int n,W,V;
    int dp[10000];
    vector<int> w,v;
    cin >> n;
    V=0;
    REP(i,n){
        w.push_back(0);
        v.push_back(0);
        cin >> w[i] >> v[i];
        V+=v[i];
    }
    cin >> W;
    
    /*
    価値v[i],重さw[i]，1回だけ選んで良い
    ※重さの合計がWを超えないように
    
    dp[j] ... 価値jを超えないような場合の最小の重さ
    
    dp[0] = 0
    dp[j] = INF
    */
    
    REP(i,V+1)
        dp[i] = INF;
    dp[0] = 0;
    
    REP(i,n){
        RFOR(j,v[i],V+1){
            dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    
    int max_v;;
    RREP(i,V+1){
        if( dp[i] <= W ){
            max_v = i;
            break;
        }
    }
    
    cout << max_v << endl;
    
    return 0;
}

