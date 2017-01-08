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
    cin >> N;
    vector<int> L(N);
    
    REP(i,N){
        cin >> L[i];
    }
    int cost = 0;
    
    while( L.size() != 1 ){
        sort(L.begin(),L.end());
        int L_new = L[0] + L[1];
        cost += L_new;
        L.erase( L.begin() );
        L.erase( L.begin() );
        L.push_back(L_new);
    }
    
    cout << cost << endl;
    
    return 0;
}

