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
    string s,t;
    cin >> N;
    cin >> s;
    
    REP(i,N){
        if( int(s[0]) < int(s[ s.size() - 1 ])  ){
            t = t + s[0];
            s = s.substr(1,s.size()-1);
        }else{
            t = t + s[s.size()-1];
            s = s.substr(0,s.size()-1);
        }
    }
    
    cout << t << endl;
    
    
    return 0;
}
