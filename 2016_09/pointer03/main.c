/* ”L‚Å‚à•ª‚©‚éC    P158 */

#include <stdio.h>

int main(void){
    int a,b;
    int *p = &a;
    
    a = 5;
    b = 10;
    
    printf("a = %d, b = %d, *p = %d\n",a,b,*p);
    p = &b;
    printf("a = %d, b = %d, *p = %d\n",a,b,*p);
    
    return 0;
}