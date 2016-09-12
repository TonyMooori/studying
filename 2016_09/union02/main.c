
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

#define TITLE_100 "100m running"
#define TITLE_200 "200m running"

#define NO 6

typedef struct{
    char name[16];
    char title[32];
    
    union{
        double tm;
        int rank;
    } seiseki;
} DATA, *LPDATA;

void myinput(LPDATA,char *,char *,char *);
void myoutput(LPDATA,int n);

int main(void){
    DATA data[NO];
    LPDATA lpdata;
    int i;
    
    lpdata = data;
    
    myinput(lpdata + 0,"Tanaka",TITLE_100, "1");
    myinput(lpdata + 1,"Sato"  ,TITLE_100, "2");
    myinput(lpdata + 2,"Kato"  ,TITLE_100, "3");
    myinput(lpdata + 3,"Yamada",TITLE_200, "10.0");
    myinput(lpdata + 4,"Suzuki",TITLE_200, "15.0");
    myinput(lpdata + 5,"Ota"   ,TITLE_200, "8.5");
    
    myoutput(lpdata,NO);
    
    return 0;
}

void myinput(LPDATA p,char name[],char title[],char seiseki[]){
    strcpy(p->name,name);
    strcpy(p->title,title);
    
    if( strcmp(title,TITLE_100) == 0 )
        (p->seiseki).rank = atoi(seiseki);
    else if( strcmp(title,TITLE_200) == 0 )
        (p->seiseki).tm = atof(seiseki);
}

void myoutput(LPDATA p,int n){
    int i;
    
    for(i=0;i < n ; i++,p++ ){
        printf("%s\t%s\t",p->name,p->title);
        if( strcmp(p->title,TITLE_100) == 0 )
            printf("%drank\n",(p->seiseki).rank);
        else if( strcmp(p->title,TITLE_200) == 0 )
            printf("%lfsec\n",(p->seiseki).tm);
    }
}

