#include <stdio.h>
#include <string.h>

#ifndef true
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

void showarray(int *x);

int main(void){
    
    int a[3] = {10,20,30};
    showarray(a);
    
    return 0;
}

void showarray(int x[]){
    int i;
    
    for( i = 0; i < 3 ; i++ )
        printf("x[%d] = %d\n",i,x[i]);
}