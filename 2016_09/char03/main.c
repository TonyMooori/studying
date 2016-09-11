#include <stdio.h>

int main(void){
    char i;
    
    for( i = '!' ; i <= '~' ; i++ ){
        printf("%3d(0x%2X) -- %c\n",i,i,i);
    }
    
    return 0;
}