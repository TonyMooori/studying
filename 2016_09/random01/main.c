
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

#define RECORD_LENGTH 6 // 6 character in 1 line(**** + \r\n)

int main(void){
    FILE *fp;
    char buffer[32];
    int number;
    
    fp = fopen("input.txt","r");
    if( fp == NULL ){
        printf("File open error.\n");
        return 0;
    }
    
    while(true){
        printf("Input the line number to read the line. (1-16)\n");
        gets(buffer);
        number = atoi(buffer);
        
        if( number <= 0 || 16 < number )break;
        
        fseek(fp, RECORD_LENGTH * (number - 1),SEEK_SET);
        if( fscanf(fp,"%s",buffer) == EOF ){
            printf("Reading file error.\n");
            continue;
        }
        
        printf(">> %s\n",buffer);
    }
    
    fclose(fp);
    
    return 0;
}
