#include <stdio.h>

int main(void){
    int a[4];
    int b[] = { 1, 2, 100, 500};
    int c[4] = { 1, 3};
    int d[] = { 1, 5, 7, };
    int i;
    
    for( i = 0 ; i < 4 ; i++ )
        printf("a[%d] = %d\n",i,a[i]);
    
    printf("\n");
    
    for( i = 0 ; i < 4 ; i++ )
        printf("b[%d] = %d\n",i,b[i]);
        
    printf("\n");
    
    for( i = 0 ; i < 4 ; i++ )
        printf("c[%d] = %d\n",i,c[i]);
    
    printf("\n");
    
    // d[] = {1,5,7, }は3つの要素になる
    for( i = 0 ; i < sizeof(d)/sizeof(int) ; i++ )
        printf("d[%d] = %d\n",i,d[i]);
    
    
    return 0;
}