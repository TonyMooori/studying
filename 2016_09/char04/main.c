#include <stdio.h>

int main(void){
    int c;
    
    for( c = 'A' ; c <= 'z' ; c++ ){
        if( ('A' <= c && c <= 'Z')
            || ('A' <= c && c <= 'Z') )
            printf("%c = %3d(0x%X)\n",c,c,c);
    }
    
    return 0;
}