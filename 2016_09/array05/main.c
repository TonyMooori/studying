#include <stdio.h>

int main(void){
    int *p;
    int i;
    int a[] = {20,40,80,100};
    
    p = a;
    
    for( i = 0; i < 4; i++){
        printf("&a[%d] = %p, (p+%d) = %p , (a+%d) = %p\n",i,&a[i],i,p+i,i,a+i);
    }
    
    return 0;
}