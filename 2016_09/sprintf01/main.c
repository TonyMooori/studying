#include <stdio.h>
#include <string.h>

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

int main(void){
    char buffer[128],name[32];
    int age;
    double height,weight;
    
    while(true){
        printf("What's your name? .... \n");
        gets(name);
        if(!strcmp(name,"")){
            printf("The null name is not supported.\n");
            continue;
        }
        break;
    }
    
    while(true){
        printf("How old are you? .... \n");
        scanf("%d",&age);
        if( age < 0 || 150 < age ){
            printf("The age value is inappropriate.\n");
            continue;
        }
        break;
    }
    
    while(true){
        printf("How tall are you? .... (cm)\n");
        scanf("%lf",&height);
        if(  height <= 0.0 || 250.0 <= height){
            printf("The tall value is inappropriate.\n");
            continue;
        }
        break;
    }
    
    while(true){
        printf("How weight are you? .... (kg)\n");
        scanf("%lf",&weight);
        if(  height <= 0.0 || 200.0 <= height){
            printf("The weight value is inappropriate.\n");
            continue;
        }
        break;
    }
    
    sprintf(buffer,
        "\nThe profile of %s(%d year-old)!!!\n"
        "tall is %5.1fcm, weight is %5.1fkg, BMI is %4.1f\n"
        ,name,age,height,weight,weight * 1e4 / (height*height));
    printf(buffer);
    
    return 0;
}
