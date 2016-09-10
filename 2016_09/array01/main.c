#include <stdio.h>

int main(void){
    int a[4];
    int i;
    
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;
    a[3] = 50;
    
    for( i = 0 ; i < 4 ; i++ )
        printf("a[%d] = %d\n",i,a[i]);
    
    for( i = 0 ; i < 4 ; i++ )
        printf("*(a+%d) = %d\n",i,*(a+i));
    
    
    return 0;
}