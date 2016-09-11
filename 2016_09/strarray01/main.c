#include <stdio.h>
#include <string.h>

int main(void){
    char a[4] = {'a','b','c','\0'};
    char b[4] = {'a','b','c'};
    char c[4] = "A";
    char d[] = "ABC";
    char e[] = {'A','B','C'};
    int i;
    
    a[0] = 'd';
    a[1] = 'e';
    a[2] = 'f';
    
    for( i = 0 ; i < sizeof(a) / sizeof(char) ; i++ ){
        printf("a[%d] = %c(0x%X)\n",i,a[i],a[i]);
    }
    printf("\n");
    
    
    for( i = 0 ; i < sizeof(b) / sizeof(char) ; i++ ){
        printf("b[%d] = %c(0x%X)\n",i,b[i],b[i]);
    }
    printf("\n");
    
    
    for( i = 0 ; i < sizeof(c) / sizeof(char) ; i++ ){
        printf("c[%d] = %c(0x%X)\n",i,c[i],c[i]);
    }
    printf("\n");
    
    
    for( i = 0 ; i < sizeof(d) / sizeof(char) ; i++ ){
        printf("d[%d] = %c(0x%X)\n",i,d[i],d[i]);
    }
    printf("\n");
    
    
    for( i = 0 ; i < sizeof(e) / sizeof(char) ; i++ ){
        printf("e[%d] = %c(0x%X)\n",i,e[i],e[i]);
    }
    printf("\n");
    
    return 0;
}