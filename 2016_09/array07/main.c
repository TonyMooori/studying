#include <stdio.h>

#define NO 3

int main(void){
    int point[][2] = {
        80, 80,
        100, 98,
        60, 80,
    };
    int i,j,sum,p_sum[NO];
    double ave;
    
    sum = 0;
    for( i = 0 ; i < NO ; i++ )
        sum += point[i][0];
    ave = (double)sum / NO;
    
    printf("英語の平均点は%5.1f点です\n",ave);
    
    sum = 0;
    for( i = 0 ; i < NO ; i++ )
        sum += point[i][1];
    ave = (double)sum / NO;
    
    printf("数学の平均点は%5.1f点です\n",ave);
    printf("\n");
    
    for( i = 0 ; i < NO ; i++ ){
        p_sum[i] = 0;
        for( j = 0 ; j < 2 ; j++ )
            p_sum[i] += point[i][j];
        
        printf("出席番号%dの人の総得点は%d点です\n",i,p_sum[i]);
    }
    
    
    return 0;
}