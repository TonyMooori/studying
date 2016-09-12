
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
    int a[3] = {1,2,3};
    
    fp = fopen("output.b","wb");
    if( fp == NULL ){
        printf("File I/O error.\n");
        return 0;
    }
    
    //  size_t fread(
    //      void *buffer,
    //      size_t size,
    //      size_t count,
    //      FILE *stream
    //  )
    fwrite(a,sizeof(int),3,fp);
    fclose(fp);
    
    
    return 0;
}
