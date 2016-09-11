#include <stdio.h>
#include <string.h>

int main(void){
    char str[64];
    
    while(1){
        printf("input string>>\n");
        gets(str);
        if( strcmp(str,"") == 0 )
            break;
        
        printf("input string is \"%s\"\n",str);
    }
    
    return 0;
}