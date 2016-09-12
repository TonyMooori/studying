    
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

char *mystrcat(char *,char *);

int main(void){
    char str1[32] = "Hello ";
    char str2[16] = "World!";
    
    printf(mystrcat(str1,str2));
    
    return 0;
}

char *mystrcat(char *a,char *b){
    char *a_original = a;
    
    while(*a)a++;
    
    while(*a++=*b++);
    
    return a_original;
}