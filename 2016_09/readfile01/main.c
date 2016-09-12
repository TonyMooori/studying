
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

typedef struct{
    char name[32];
    char tel[32];
}DATA,*LPDATA;

int read_data(FILE *,LPDATA);
void show_data(LPDATA);

int main(void){
    FILE *fp;
    DATA data;
    
    fp = fopen("input.txt","r");   // add string end of the file
        
    if( fp == NULL ){
        printf("fopen was failed.\n");
        return 0;
    }
    
    while(read_data(fp,&data) == true ){
        show_data(&data);
    }
    
    fclose(fp);
    
    return 0;
}

int read_data(FILE *fp,LPDATA p){
    return fscanf(fp,"%s %s",p->name,p->tel) != EOF;
}

void show_data(LPDATA p){
    printf("%16s    %16s\n",p->name,p->tel);
}
