#include <stdio.h>

int main(void){
    int a[4] = {1,2,3,4};
    int *p;
    int i;
    
    p = a;
    
    for( i = 0 ; i < 4 ; i++ )
        printf("&a[%d] = %p\n",i,&a[i]);
    printf("\n");
    
    for( i = 0 ; i < 4 ; i++ )
        printf("a[%d] = %d\n",i,a[i]);
    printf("\n");
    
    
    // int型のポインタ
    // → 変な部分を参照しないようにコンパイラが調整
    // → +1 とするとint型一つ分と解釈されるので4byteすすむ
    
    for( i = 0 ; i < 4 ; i++ )
        printf("*(p+%d) = %d\n",i,*(p+i));
    printf("\n");
    
    return 0;
}