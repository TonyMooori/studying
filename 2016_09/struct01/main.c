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

struct Man{
    char name[32];
    int age;
};


int main(void){
    struct Man student;
    
    strcpy(student.name,"Taro Yamada");
    student.age = 16;
    
    printf("The student name is %s.\n",student.name);
    printf("The student age is %d.\n",student.age);
    
    return 0;
}
