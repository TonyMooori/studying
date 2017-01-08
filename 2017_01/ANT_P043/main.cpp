#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;

int main(void){
    
    int n;
    cin >>n;
    vector<int> start,end;
    
    // 入力処理
    int ans= 0;
    int t = 0;
    
    REP(i,n){
        int at = -1;
        int min_end = 1e9;
        
        REP(j,n){
            if( t <= start[j] && min_end > end[j]){
                min_end = end[j];
                at = j;
            }
        }
        
        if( at != -1 ){
            t = end[at];
            ans++;
        }else{
            break;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
