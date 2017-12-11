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

#define MAX_N 256
/*
int par[MAX_N];
int rank[MAX_N];
map<int,int64_t> hash_ori;
map<int64_t,int> ori_hash;

void init(int64_t a,int64_t b){
    for(int i=0;i<MAX_N;i++){
        par[i] = i;
        rank[i] = 0;
    }
    
    for(int64_t i=a;i<b;i++){
        int h = i % 100;
        hash_ori[h] = i;
        ori_hash[i] = h;
    }
}

int find_root_hash(int64_t x){
    int h = ori_hash[x];
    
    if( par[h] == h){
        return h;
    }else{
        return par[h] = find_root_hash(hash_ori[par[h]]);
    }
}

void unite(int64_t x,int64_t y){
    int hx = find_root_hash(x);
    int hy = find_root_hash(y);
    
    if( hx == hy )return;
    if( rank[hx] < rank[hy] ){
        par[hx] = hy;
    }else{
        par[hy] = hx;
        if( rank[hx] == rank[hy] ) rank[hx]++;
    }
}

bool same(int64_t x,int64_t y){
    return find_root_hash(x) == find_root_hash(y);
}
*/
int64_t gcd( int64_t m, int64_t n )
{
    // 引数に０がある場合は０を返す
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;

    // ユークリッドの方法
    while( m != n )
    {
        if ( m > n ) m = m - n;
        else         n = n - m;
    }
    return m;
}

bool has_relative(int64_t n,int64_t m){
    return gcd(n,m) != 1;
}

bool table[100][100];
bool prime[100];
vector<int64_t> s;
vector<int64_t> using_vals;

int64_t solve(){
    if (s.size()==0){
        
        return 1;
    }
    int64_t& n = s.back();
    s.pop_back();
    s.push_back(n);
    
    
    if( prime[n%100] ){
        int ret = 2*solve();
         s.push_back(n);
        return ret;
    }else{
        // 使ったことを言わないと駄目
        bool flag=true;
        
        
        for(int j = 0 ;  j < using_vals.size() ; j++ ){
            int u = using_vals[j];
            
            if( table[n%100][u%100] ){
                flag = false;
                break;
            }
        }
        
        if( flag ){
            using_vals.push_back(n);
            int64_t r1 = solve();
            using_vals.pop_back();
            int64_t r2 = solve();
            s.push_back(n);
            return r1+r2;
        }else{
            int ret =solve();
        s.push_back(n);
            return ret;
        }
    }
}


int main(void){
    int64_t a,b;
    cin >> a >> b;
    b++;
    
    REP(i,100)prime[i]=false;
    REP(i,100)REP(j,100)table[i][j]=false;
    
    for(int64_t n1 = a ; n1 < b ; n1++ ){
        for(int64_t n2 = a ; n2 < b ; n2++ ){
            if( has_relative(n1,n2)){
                int h1 = n1 % 100;
                int h2 = n2 % 100;
                
                table[h1][h2]=true;
                table[h2][h1]=true;
            }
        }
        int64_t cnt=0;
        for(int64_t n2 = a ; n2 < b ; n2++ ){
            if(table[n1%100][n2%100])cnt++;
        }
        
        if( cnt == 1 ){
            prime[n1%100] = true;
            //cout << n1 << endl;
        }
    }
    for(int64_t n2 = a ; n2 < b ; n2++ ){
        s.push_back(n2);
    }
    
    cout << solve() << endl;
    
    return 0;
}


