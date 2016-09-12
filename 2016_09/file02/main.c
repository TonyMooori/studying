
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

int write_data(FILE *);

int main(void){
    FILE *fp;
    char filename[256];
    
    printf("input file name >> ");
    scanf("%s",filename);
    
    fp = fopen(filename,"a");   // add string end of the file
        
    if( fp == NULL ){
        printf("fopen was failed.\n");
        return 0;
    }
    
    printf("Type something to write file.\n");
    printf("Input NULL string to finish .\n");
    while(write_data(fp) == true );
    
    fclose(fp);
    
    return 0;
}

int write_data(FILE *fp){
    char data[256];
    
    rewind(stdin);
    printf(">> ");
    gets(data);
    
    if( strcmp(data,"") == 0 )return false;
    
    fprintf(fp,data);
    fprintf(fp,"\n");
    return true;
}
