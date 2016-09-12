    
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
    int (*ptr)();
    
    ptr = func;
    
    printf("%d\n",ptr(1));
    
    return 0;
}

int func(int a){
    return a*2;
}
