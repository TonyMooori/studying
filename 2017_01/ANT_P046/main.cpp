#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;

int main(void){
    int N;
    int R;
    cin >> N >> R;
    vector<int> x(N);
    int ans = 0;
    
    REP(i,N){
        cin >> x[i];
    }
    
    int at = 0;
    while(true){
        int end_at = at;
        while( end_at < N && x[end_at] - x[at] <= R )
            end_at++;
        int check_x = x[end_at-1];
        
        at = end_at - 1;
        while(  at < N && x[at] - check_x <= R )
            at++;
        
        ans++;
        if( at >= N )
            break;
        
    }
    
    
    cout << ans << endl;
    
    
    return 0;
    
}
