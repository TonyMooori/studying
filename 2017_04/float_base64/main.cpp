#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include "Base64.h"

#ifndef USEFUL_MACROS
#define USEFUL_MACROS
#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#endif

using namespace std;

int main(void){
    float datas[5] = {0.1,0.2,0.3,0.4,0.5};
    char *base64;
    float *decoded_data;
    int n_base64,n_byte;
    
    n_base64 = encode_b64((uint8_t*)datas, 5*4, &base64);
    n_byte = decode_b64(base64, (uint8_t**)(&decoded_data));
    
    
    printf("base64:  %s\n\n",base64);
    REP(i,n_byte/4)
        printf("decoded_data[%02d] = %f\n",i,decoded_data[i]);
    
    free(base64);
    free(decoded_data);
    return 0;
}
