
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

// 写経と言いつつ写経じゃない

int main(void){
    char str1[256];
    char str2[256];
    char *ret;
    
    printf("input string 1 >> \n");
    gets(str1);
    printf("string 1 is %s\n",str1);
    printf("input string 2 >> \n");
    gets(str2);
    printf("string 2 is %s\n",str2);
    
    ret = strstr(str1,str2);
    
    if( ret == NULL ){
        printf("\"%s\" doesn't contain \"%s\".\n",str1,str2);
    }else{
        printf("%s\n",ret);
    }
    
    return 0;
}
