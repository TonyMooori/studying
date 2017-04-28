/**
 * @file Base64.h
 * @brief The base64 encoder/decoder
 * @author null
 * @date 2017/04/29
 */
 
#ifndef BASE64_HEADER_FILE
#define BASE64_HEADER_FILE

#ifndef USEFUL_MACROS
#define USEFUL_MACROS
#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#endif

#include <stdio.h>
#include <string.h>

const uint8_t table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
const uint8_t lut[256] = {
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63, 52, 53, 54,
    55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64, 64,  0,  1,  2,
     3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64, 64, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64
};

/**
 * @fn To decode a base64 string data to the original data.
 * @param (base64) The string data of base64.
 * @param (ret) The pointer of pointer of the original data.
 * @return The bytes of original data.
 */
int decode_b64(char *base64,uint8_t **ret){
    int n_len = strlen(base64);
    int n_ret = (n_len/4)*3;
    *ret = (uint8_t*)malloc(n_ret*sizeof(uint8_t));
    
    REP(i,n_len/4){
        (*ret)[i*3+0] = ((lut[base64[i*4+0]]&0x3F)<<2)|((lut[base64[i*4+1]]&0x30)>>4);
        (*ret)[i*3+1] = ((lut[base64[i*4+1]]&0x0F)<<4)|((lut[base64[i*4+2]]&0x3C)>>2);
        (*ret)[i*3+2] = ((lut[base64[i*4+2]]&0x03)<<6)|((lut[base64[i*4+3]]&0x3F)>>0);
    }
    
    if( n_len>=1&&base64[n_len-1]=='='){
        n_ret--;
        if( n_len>=2&&base64[n_len-2]=='=')
            n_ret--;
    }
    
    return n_ret;
}

/**
 * @fn To encode a the original data to the base64 string.
 * @param (bytes) The original data.
 * @param (n_bytes) The bytes of original data.
 * @param (ret) The pointer of pointer of the base64 string.
 * @return The length of base64 string.
 */
int encode_b64(uint8_t *bytes,int n_bytes,char **ret){
    //const int n_bytes = n_num*4;
    int n_ret = (n_bytes / 3 + (n_bytes%3==0?0:1))*4;
    *ret = (char*)malloc((1+n_ret)*sizeof(char));
    
    REP(i,n_bytes/3){
        (*ret)[i*4+0]=(0xFC&bytes[i*3+0])>>2;
        (*ret)[i*4+1]=((0x03&bytes[i*3+0])<<4)|((0xF0&bytes[i*3+1])>>4);
        (*ret)[i*4+2]=((0x0F&bytes[i*3+1])<<2)|((0xC0&bytes[i*3+2])>>6);
        (*ret)[i*4+3]=(0x3F&bytes[i*3+2]);
    }
    
    if( n_bytes%3==1 ){
        (*ret)[n_ret-4]=(0xFC&bytes[n_bytes-1])>>2;
        (*ret)[n_ret-3]=(0x03&bytes[n_bytes-1])<<4;
        (*ret)[n_ret-2]=64;
        (*ret)[n_ret-1]=64;
    }else if( n_bytes%3 == 2 ){
        (*ret)[n_ret-4]=(0xFC&bytes[n_bytes-2])>>2;
        (*ret)[n_ret-3]=((0x03&bytes[n_bytes-2])<<4)|((0xF0&bytes[n_bytes-1])>>4);
        (*ret)[n_ret-2]=(0x0F&bytes[n_bytes-1])<<2;
        (*ret)[n_ret-1]=64;
    }
    
    REP(i,n_ret){
        (*ret)[i] = table[(*ret)[i]];
    }
    (*ret)[n_ret]=0;
    
    return strlen(*ret);
}

#endif

