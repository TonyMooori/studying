#include <stdio.h>
#include <string.h>

int main(void){
    char str[64];
    
    printf("input string >> \n");
    // スペースがあっても大丈夫な入力手法
    gets(str);
    printf("str is \"%s\"\n",str);
    
    
    return 0;
}