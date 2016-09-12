
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef true
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

char *mystrcat(char *str1,char *str2);

int main(void){
    char str1[256] = "Hello ";
    char str2[256] = "World!";
    
    mystrcat(str1,str2);
    
    printf("%s\n",str1);
    
    return 0;
}

char *mystrcat(char *str1,char *str2){
    str1 = str1 + strlen(str1);
    
    while(*(str2) != '\0'){
        *(str1) = *(str2);
        str1++;
        str2++;
    }
    
    return str1;
}
