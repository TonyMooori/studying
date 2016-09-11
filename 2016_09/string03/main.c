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
        printf("%s‚Í%s‚æ‚è‘O‚É‚ ‚è‚Ü‚·\n",str1,str2);
    else if( cmp > 0 )
        printf("%s‚Í%s‚æ‚èŒã‚É‚ ‚è‚Ü‚·\n",str1,str2);
    else 
        printf("%s‚Æ%s‚Í“¯‚¶•¶Žš—ñ‚Å‚·\n",str1,str2);
    
    return 0;
}