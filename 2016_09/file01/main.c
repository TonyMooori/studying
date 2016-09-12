
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef true
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

#include <stdio.h>

int main(void){
    FILE *fp;
    
    fp = fopen("output.txt","w");
    
    if( fp == NULL ){
        printf("fopen was failed.\n");
        return 0;
    }
    
    fprintf(fp,"My firt file output.\n");
    
    if( fclose(fp) != 0 ){
        printf("fclose was failed.\n");
        return 0;
    }
    
    return 0;
}
