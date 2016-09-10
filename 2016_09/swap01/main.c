/* ”L‚Å‚à•ª‚©‚éC    P159 */

#include <stdio.h>

void swap1(int a,int b);
void swap2(int *a,int *b);

int main(void){
    int a = 10;
    int b = 5;
    
    printf("a = %d,b = %d\n",a,b);
    
    swap1(a,b);
    printf("a = %d,b = %d\n",a,b);
    
    swap2(&a,&b);
    printf("a = %d,b = %d\n",a,b);
    
    return 0;
}

void swap1(int a,int b){
    int temp = b;
    b = a;
    a = temp;
}

void swap2(int *a,int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
