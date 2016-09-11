#include <stdio.h>
#include <string.h>

#ifndef true
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

void showname(char **);

int main(void){
    char *name[] = {
        "Taro",
        "Jiro",
        "Saburo",
        "Siro"
    };
    
    showname(name);
    
    return 0;
}

void showname(char **p){
    int i;
    
    for( i = 0; i < 4 ; i++ )
        printf("%s\n",p[i]);
}