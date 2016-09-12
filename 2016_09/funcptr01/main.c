    
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

int func(int);

int main(void){
    printf("main ... %p\n",main);
    printf("main ... %p\n",func);
    
    return 0;
}

int func(int a){
    return a*2;
}
