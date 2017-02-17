#include <iostream>
#include <queue>
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

#define N 100

vector<int> get_primes(vector<int> xs){
    vector<int> ret;
    int p;
    
    if( xs.size() == 0 )
        return ret;
    
    p = xs[0];
    FOR(i,1,xs.size())
        if( xs[i] % p != 0 )
            ret.push_back(xs[i]);
    
    ret = get_primes(ret);
    ret.push_back(p);
    
    return ret;
}

int main(void){
    vector<int> xs,primes;
    FOR(i,2,N+1)
        xs.push_back(i);
    
    primes = get_primes(xs);
    REP(i,primes.size())
        cout << primes[i] << endl;
    
    return 0;
}
