
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


typedef struct _tagDATA{
    char name[32];
    int age;
    struct _tagDATA *nextdata;
} DATA;

int main(void){
    DATA a = {"Taro",20,};
    DATA b = {"Jiro",21,};
    DATA c = {"Saburo",22,};
    
    DATA *lpdata;
    
    a.nextdata = &b;
    b.nextdata = &c;
    c.nextdata = NULL;
    
    for(lpdata = &a ; lpdata != NULL ; lpdata = lpdata->nextdata ){
        printf("The age of %s is %d\n",lpdata->name,lpdata->age);
    }
    
    return 0;
}
