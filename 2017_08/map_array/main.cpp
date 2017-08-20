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

template<typename T>
T mapping(const T x,const T in_min,const T in_max,const T out_min,const T out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

template<typename T>
T mapping_array(const T x,const T *from,const T *to,int n_array){
    if( x <= from[0] )
        return to[0];
        
    if( x >= from[n_array-1])
        return to[n_array-1];

    for(int i = 0 ; i < n_array - 1 ; i++ ){
        if( x <= from[i+1] )
            return mapping<T>(x,from[i],from[i+1],to[i],to[i+1]);
    }
    return to[n_array-1];
}


int main(void){
    
    // 100, 200, 400 , 800
    // 1000, 2000, 4000, 8000
    const float from_array[4] = {100, 200, 400 , 800};
    const float to_array[4] = {1000, 2000, 4000 , 8000};
    const float test_case[] = {50,150,200,250,350,400,450,650,800,900};
    
    
    REP(i,10){
        cout << test_case[i] << "\t";
        cout << mapping_array<float>(test_case[i],from_array,to_array,4) << endl;
    }
    cout <<  mapping_array<float>(800,from_array,to_array,4) << endl;
    return 0;
}
