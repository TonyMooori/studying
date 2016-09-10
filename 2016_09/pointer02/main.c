/* ”L‚Å‚à•ª‚©‚éC    P157 */

#include <stdio.h>

int main(void){
    int a;
    int *pa;
    
    pa = &a;
    *pa = 5;
   
    printf("a   = %d\n",a);
    printf("*pa = %d\n",*pa);
    
    return 0;
}