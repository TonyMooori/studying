
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

union myunion{
    int i;
    double d;
    char c;
    char *str;
};

int main(void){
    union myunion u;
    
    u.i = 200;
    printf("u.i = %d\n",u.i);
    u.d = 92.25 ;
    printf("u.d = %lf\n",u.d);
    u.c = 'A';
    printf("u.c = %c\n",u.c);
    u.str = "ABC";
    printf("u.str = \"%s\"\n",u.str);
    
    return 0;
}
