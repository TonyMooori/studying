#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>

#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;

void floatToBytes(float f,uint8_t output[4]){
    uint8_t *temp = (uint8_t*)(&f);
    
    REP(i,4)
        output[i] = temp[i];
}

void bytesToFloat(uint8_t bytes[4],float *output){
    uint8_t *temp = (uint8_t*)(output);
    
    REP(i,4)
        temp[i] = bytes[i];
}

int main(void){
    float f = 3.14159265358979323f;
    float g;
    uint8_t bytes[4];
    
    floatToBytes(f,bytes);
    
    REP(i,4)
        printf("0x%02x ",bytes[i]);
    printf("\n");
    
    bytesToFloat(bytes,&g);
    printf("%lf\n",g);
    
    return 0;
}
