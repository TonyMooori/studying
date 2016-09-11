#include <stdio.h>
#include <string.h>

#ifndef true
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

// 演算子の順序上，
// int **
// int (*m)[2]
// int m[][2]
// などと書ける(indexの値は無視されるよう)
void showint(int (*m)[2]);

int main(void){
    int a[][2] = {
        1,2,
        3,4,
        5,6,
        7,8
    };
    
    showint(a);
    
    return 0;
}

void showint(int (*m)[2]){
    int i,j;
    
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            printf("m[%d][%d] = %d\n",i,j,m[i][j]);
        }
    }
}
