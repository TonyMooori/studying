    
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
    int (*ptr1)(),(*ptr2)();
    
    ptr1 = main;
    ptr2 = func;
    
    printf("main ... %p, ptr1 ... %p \n",main,ptr1);
    printf("main ... %p, ptr1 ... %p \n",func,ptr2);
    
    return 0;
}

int func(int a){
    return a*2;
}
