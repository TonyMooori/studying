
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
    int a[3];
    char buf[8] = {'\0'};
    
    fp = fopen("output.b","rb");
    if( fp == NULL ){
        printf("File I/O error.\n");
        return 0;
    }
    
    fread(a,sizeof(int),3,fp);
    fread(buf,sizeof(char),3,fp);
    fclose(fp);
    
    printf("%d,%d,%d\n",a[0],a[1],a[2]);
    printf("%s\n",buf);
    
    return 0;
}
