/* 猫でも分かるC    P151 */

#include <stdio.h>

int main(void){
    char c;
    int i;
    double d,e;
    
    printf("変数cのアドレスは%pです\n",&c);
    printf("変数iのアドレスは%pです\n",&i);
    printf("変数dのアドレスは%pです\n",&d);
    printf("変数eのアドレスは%pです\n",&e);
    
    return 0;
}