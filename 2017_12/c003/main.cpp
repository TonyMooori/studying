#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>


#ifndef _USEFUL_MACROS_
#define _USEFUL_MACROS_
#define INF 99999999
#define N_PRIME 1000000007
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define OUTPUT_DEBUG
#ifdef OUTPUT_DEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x) do{}while(false)
#endif
#endif 

using namespace std;


int main(){
    int64_t n,k;
    cin >> n >> k;
    
    vector<int64_t> counter(200005);
    REP(i,n){
        int temp;
        cin >> temp;
        counter[temp]++;
    }
    
    priority_queue<int, vector<int>, std::greater<int> > q;
    
    int n_color = 0;
    REP(i,200005){
        if( counter[i] > 0 ){
            q.push(counter[i]);
            n_color++;
        }
    }
    
    int ans=0;
    
    while(true){
        if( n_color <= k )break;
        
        
        ans += q.top();
        q.pop();
        n_color--;
    }
    
    cout << ans << endl;
    
    
}