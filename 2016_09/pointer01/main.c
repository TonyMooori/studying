/* 猫でも分かるC    P155 */

#include <stdio.h>

int main(void){
    int a;
    int *lpa;
    
    lpa = &a;
    
    printf("適当な整数値を入力 --- ");
    scanf("%d",&a);
    printf("変数aに%dが代入されました\n",a);
    printf("変数aのアドレスは%pです\n",&a);
    printf("変数aを指しているポインタはlpaです(lpa は %p)\n",lpa);
    printf("*lpaの値は%dです\n",*lpa);
    
    return 0;
}