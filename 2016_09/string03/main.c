#include <stdio.h>

int main(void){
    char str1[32];
    char str2[32];
    int cmp;
    
    printf("input str1....\n");
    scanf("%s",str1);
    printf("input str2....\n");
    scanf("%s",str2);
    
    cmp = strcmp(str1,str2);
    if(cmp < 0)
        printf("%sは%sより前にあります\n",str1,str2);
    else if( cmp > 0 )
        printf("%sは%sより後にあります\n",str1,str2);
    else 
        printf("%sと%sは同じ文字列です\n",str1,str2);
    
    return 0;
}