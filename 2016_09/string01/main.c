#include <stdio.h>

int main(void){
    char *str;
    int i;
    str = "ABC";
    
    for( i=0 ; i < 3 ; i++ )
        printf("*(str+%d) = %c\n",i,*(str+i));
    
    for( i=0 ; i < 3 ; i++ )
        printf("str[%d] = %c\n",i,str[i]);
    
    return 0;
}