#include <stdio.h>
#include <string.h>

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

int main(int argc,char *argv[]){
    int i;
    
    if( argc == 1 ){
        printf("No command line arguments.\n");
        return 0;
    }
    
    for(i = 0 ; i < argc ; i++ ){
        printf("argv[%d] is %s\n",i,argv[i]);
    }
    return 0;
}
