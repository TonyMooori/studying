    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef true
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

double add(double,double);
double sub(double,double);
double mul(double,double);
double division(double,double);

int main(void){
    double (*ptr[4])() = { add, sub,mul,division};
    double a,b;
    int cmd;
    
    printf("select mode >>\n");
    printf("1: addition\n");
    printf("2: subtraction\n");
    printf("3: multiplication\n");
    printf("4: division\n");
    
    scanf("%d",&cmd);
    if( cmd < 0 || 4 < cmd ){
        printf("Bad command\n");
        return 0;
    }
    
    printf("input value 1\n");
    scanf("%lf",&a);
    printf("input value 2\n");
    scanf("%lf",&b);
    printf("ans = %lf\n",ptr[cmd-1](a,b));
    
    return 0;
}

double add(double a,double b){return a+b;}
double sub(double a,double b){return a-b;}
double mul(double a,double b){return a*b;}
double division(double a,double b){return a/b;}