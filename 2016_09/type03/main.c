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

#define N 10

typedef struct DATA{
    char name[32];
    char tel[32];
} MYDATA, *LPMYDATA;

int menu();
void meibo_input(LPMYDATA);
void meibo_output(LPMYDATA);

int main(void){
    int selectno,loopend = 0;
    
    MYDATA mydata[N];
    LPMYDATA lpMydata = mydata;
    
    memset(&mydata,0,sizeof(mydata));
    
    while(true){
        selectno = menu();
        
        printf("\n");
        switch(selectno){
            case 1:
                meibo_input(lpMydata);
                break;
            case 2:
                meibo_output(lpMydata);
                break;
            default:
                loopend = 1;
                break;
        }
        printf("\n");
        if( loopend == 1 )break;
    }
    
    return 0;
}

int menu(){
    int ret = 0;
    
    printf("1:      input data\n");
    printf("2:      output data\n");
    printf("other:  end\n");
    
    scanf("%d",&ret);
    
    return ret;
}

void meibo_input(LPMYDATA p){
    int n = -1;
    rewind(stdin);
    do{
        printf("input data number(0-%d)",N-1);
        scanf("%d",&n);
    }while( n < 0 || N <= n );
    
    rewind(stdin);
    printf("input name >>\n");
    gets(p[n].name);
    printf("input telephone number >>\n");
    gets((p+n)->tel);
}

void meibo_output(LPMYDATA p){
    int i;
    
    for( i = 0; i < N ; i++ ){
        printf("**************\n");
        printf("name    :%s\n",(*(p+i)).name);
        printf("tel     :%s\n",(p+i)->tel);
        printf("**************\n");
    }
}


