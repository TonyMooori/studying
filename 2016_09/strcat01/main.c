#include <stdio.h>
#include <string.h>

int main(void){
    char name[64];
    char dr[] = "Dr.";
    
    printf("input your name...\n");
    gets(name);
    
    printf("%s, please come in!\n",
        strcat(dr,name));
    
    return 0;
}
