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
#include <stdlib.h>
#include <time.h>

struct Data{
    char name[32];
    int age;
    double height;
    double weight;
    double bmi;
};

void struct_input(struct Data *);
void struct_output(struct Data *);

int main(void){
    struct Data MyData;
    
    struct_input(&MyData);
    struct_output(&MyData);
    
    return 0;
}

void struct_input(struct Data *p){
    printf("input name >>\n");
    scanf("%s",p->name);
    printf("input age >>\n");
    scanf("%d",&(p->age));
    printf("input height(cm) >>\n");
    scanf("%lf",&(p->height));
    printf("input weight(kg) >>\n");
    scanf("%lf",&(p->weight));
    
    p->bmi = 1e4 * p->weight / (p->height*p->height);
}

void struct_output(struct Data *p){

    printf("*******************\n");
    
    printf("name:       %s\n",p->name);
    printf("age:        %d\n",p->age);
    printf("height:     %lf\n",p->height);
    printf("weight      %lf\n",p->weight);
    printf("bmi         %lf\n",p->bmi);
    
    printf("*******************\n");
}