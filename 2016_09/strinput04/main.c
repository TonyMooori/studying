#include <stdio.h>
#include <string.h>

int main(void){
    char str[64];
    
    do{
        printf("input string>>\n");
    }while( (strcmp(gets(str),"") != 0) 
        && (printf("input string is \"%s\"\n",str) || 1 )
    );
    
    return 0;
}