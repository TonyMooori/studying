#include <stdio.h>
#include <string.h>

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

int main(void){
    
    char *str[6] = {
        "abc",
        "de",
        "fghi",
        "jklmnop",
        "qrs",
        "tuvwxyz",
    };
    
    int i;
    for( i = 0 ; i < 6 ; i ++ )
        printf(str[i]);
    
    printf("\n");
    
    
    return 0;
}
