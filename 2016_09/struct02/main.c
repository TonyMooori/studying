#include <stdio.h>
#include <string.h>

#ifndef true
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

#include <stdio.h>
#include <string.h>

struct DATA{
    int data1;
    char data2;
    char data3[32];
};

int main(void){
    struct DATA mydata = { 10, 'A', "cat"};
    
    printf("data1: %d\n",mydata.data1);
    printf("data2: %c\n",mydata.data2);
    printf("data3: %s\n",mydata.data3);
    
    return 0;
}

