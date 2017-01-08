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

#define N 256

using namespace std;

const string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

vector<bool> to_bin(const char c){
    int b = 0b10000000;
    vector<bool> ret;
    
    while(b != 0){
        ret.push_back( (b&c) != 0 );
        b >>= 1;
    }
    
    return ret;
}

char to_char(const vector<bool> v,const int at){
    int ret = 0;
    REP(i,6){
        ret <<= 1;
        if( v[i+at] )
            ret += 1;
    }
    return table[ret];
}

int main(void){
    string data;
    vector<bool> bin_data;
    string res;
    
    cin >> data;
    REP(i,data.size()){
        vector<bool> temp = to_bin(data[i]);
        REP(i,temp.size())
            bin_data.push_back(temp[i]);
    }
    
    
    while( bin_data.size() % 6 != 0 )
        bin_data.push_back(false);
    
    REP(i,bin_data.size()/6){
        res += to_char(bin_data,i*6);
    }
    
    while( res.size() % 4 != 0 )
        res += "=";
    
    cout << res << endl;
    
    return 0;
}

