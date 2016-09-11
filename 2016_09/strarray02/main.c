#include <stdio.h>
#include <string.h>

int main(void){
    char str[64] = "ABC";
    
    printf("%s\n",str);
    strcpy(str,"def");
    printf("%s\n",str);
    
    return 0;
}
