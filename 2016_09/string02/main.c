#include <stdio.h>

int main(void){
    int i;
    
    for( i = 0 ; i < 3; i++ )
        printf("\"ABC\"[%d] = %c\n",i,"ABC"[i]);
    
    for( i = 0 ; i < 3; i++ )
        printf("%d[\"ABC\"] = %c\n",i,i["ABC"]);
    
    
    return 0;
}