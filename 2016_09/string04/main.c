#include <stdio.h>
#include <string.h>

int main(void){
    char str[32];
    size_t len;
    
    printf("input str\n");
    scanf("%s",str);
    
    len = strlen(str);
    printf("%s�̕�����̒�����%d�ł�\n",str,len);
    
    return 0;
}