
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

int main(void){
    FILE *fp;
    unsigned char temp;
    int counter = 0;
    
    fp = fopen("output.b","rb");
    if( fp == NULL ){
        printf("File I/O error.\n");
        return 0;
    }
    
    while(fread(&temp,sizeof(unsigned char),1,fp) != 0 ){
        printf("%02X ",temp);
        counter++;
        
        if( counter % 5 == 0 )printf("\n");
    }
    fclose(fp);
    
    return 0;
}
