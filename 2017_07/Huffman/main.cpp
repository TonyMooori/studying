#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <stack>


#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;


typedef struct _data_t {
    int val;
    int count;
    uint64_t code;
    bool is_leaf;
    _data_t *left;
    _data_t *right;
    
    bool operator<( const _data_t& right ) const {
        return count < right.count;
    }
} data_t;

string tobin(uint64_t a){
    string ret = "";
    
    while(a){
        ret = (a%3==1?"1":"0")+ret;
        a/=3;
    }
    
    return ret;
}

int main(void){
    const int n = 256;
    int x[n];
    int c[n];
    uint64_t h[n];
    data_t temp,temp2;
    vector<data_t> work;
    stack< data_t > stk;
    
    REP(i,n){
        x[i] = i;
        c[i] = rand()%30;
    }
    
    REP(i,n){
        temp.val = i;
        temp.count = c[i];
        temp.is_leaf = true;
        
        work.push_back(temp);
    }
    
    while(work.size()>1){
        sort(work.begin(),work.end());
        
        data_t *pd1 = (data_t*)malloc(sizeof(data_t));
        data_t *pd2 = (data_t*)malloc(sizeof(data_t));
        
        *pd1 = work[0]; work.erase(work.begin());
        *pd2 = work[0]; work.erase(work.begin());
        
        temp.count= pd1->count + pd2->count;
        temp.is_leaf = false;
        temp.left = pd1;
        temp.right = pd2;
        
        work.push_back(temp);
    }
    
    work[0].code = 0;
    stk.push(work[0]);
    
    while(stk.size()){
        temp = stk.top(); stk.pop();
        
        if( temp.is_leaf ){
            h[ temp.val ] = temp.code;
        }else{
            temp2 = *temp.left;
            free(temp.left);
            temp2.code = temp.code * 3 + 1;
            stk.push(temp2);
            
            temp2 = *temp.right;
            free(temp.right);
            temp2.code = temp.code * 3 + 2;
            stk.push(temp2);
        }
    }
    
    REP(i,n){
        cout << x[i] << "\t" << c[i] << "\t" << tobin(h[i]) << endl;
    }
}

/*
typedef struct _data_t {
    int val;
    int count;
    bool is_leaf;
    _data_t *left;
    _data_t *right;
    
    bool operator<( const _data_t& right ) const {
        return count < right.count;
    }
} data_t;

uint8_t clump(float x);
void make_data(const char filename[256]);
void zip(const char from_path[256],const char to_path[256]);
void unzip(const char from_path[256],const char to_path[256]);

int main(void){
    
    
    
    return 0;
}

void zip(const char from_path[256],const char to_path[256]){
    FILE *fp;
    int n_size;
    uint8_t *buff;
    data_t arr[256];
    
    fp = fopen(from_path,"rb");
    
    if( fp == NULL ){
        cout << "Error: Can't open file >" << from_path << endl;
        exit(0);
    }
    
    fread(&n_size,sizeof(int),1,fp);
    buff = (uint8_t*)malloc(n_size*sizeof(uint8_t));
    fread(buff,sizeof(uint8_t),n_size,fp);
    
    REP(i,256){
        arr[i].val = i;
        arr[i].is_leaf = true;
        arr[i].count = 0;
    }
    
    REP(i,n_size){
        arr[ buff[i] ].count++;
    }
    
    REP
    
    
    free(buff);
}


uint8_t clump(float x){
    if( x < 0 )return 0;
    else if( x > 255 ) return 255;
    else return (uint8_t)x;
}

void make_data(const char filename[256]){
    FILE *fp;
    const int n_data = 4096;
    const int k = 111;
    uint8_t buff[n_data];
    float x;
    
    REP(i,n_data){
        // 2*pi*k*i/n_data
        x = 2.0f*M_PI*k*i/n_data;
        // 8bitに収まる範囲に離散化する
        buff[i] = clump(127*(1+sin(x)));
    }
    
    
    fp = fopen(filename,"wb");
    
    if( fp == NULL ){
        cout << "Error: Can't open file >" << filename << endl;
        exit(0);
    }
    
    // 配列のサイズ数を書き込む
    fwrite(buff,sizeof(int),n_data,fp);
    // サイン関数のデータを書き込む
    fwrite(buff,sizeof(uint8_t),n_data,fp);
    
    fclose(fp);
}

*/