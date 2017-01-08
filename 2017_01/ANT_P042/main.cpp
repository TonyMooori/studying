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
    
    int V[6] = {1,5,10,50,100,500};
    int C[6];
    int A;
    int ans = 0;
    
    cin >> A;
    RREP(i,6){
        int t = min( A/V[i], C[i] );
        A -= t * V[i];
        ans += t;
    }
    
    cout << asn << endl;
    
    return 0;
}
