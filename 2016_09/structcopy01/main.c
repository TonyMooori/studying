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

#define STUDENT_NO  5
#define SUBJECT_NO  3
#define NAME_LENGTH 64

struct SEISEKI{
    char name[32];
    int japanese;
    int mathematics;
    int english;
};

void show_profile(struct SEISEKI person,int sum);

int main(void){
    struct SEISEKI myclass[STUDENT_NO];
    char name[STUDENT_NO][NAME_LENGTH] = {
        "Tanaka", "Sato", "Suzuki", "Ota", "Kato"
    };
    int i;
    int sum_subject[SUBJECT_NO] = {0};
    int sum_person[STUDENT_NO] = {0};
    
    srand(time(NULL));
    
    for( i = 0 ; i < STUDENT_NO ; i++ ){
        strcpy(myclass[i].name,name[i]);
        myclass[i].japanese = rand() % 80 + 21; 
        myclass[i].mathematics = rand() % 80 + 21; 
        myclass[i].english = rand() % 80 + 21; 
        
        sum_subject[0] += myclass[i].japanese;
        sum_subject[1] += myclass[i].mathematics;
        sum_subject[2] += myclass[i].english;
        
        sum_person[i] = 
              myclass[i].japanese 
            + myclass[i].mathematics
            + myclass[i].english;
        
        show_profile(myclass[i],sum_person[i]);
    }
    
    printf("***********************\n");
    printf("japanese:       %d\n",sum_subject[0]);
    printf("mathematics:    %d\n",sum_subject[1]);
    printf("english:        %d\n",sum_subject[2]);
    
    
    
    return 0;
}

void show_profile(struct SEISEKI person,int sum){
    printf("name:           %s\n",person.name);
    printf("japanese:       %d\n",person.japanese);
    printf("mathematics:    %d\n",person.mathematics);
    printf("english:        %d\n",person.english);
    printf("sum:            %d\n",sum);
    
    printf("\n");
}
