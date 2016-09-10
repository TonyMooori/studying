#include <stdio.h>

int main(void){
    int a[3][2] = { 10, 20, 30, 40, 50, 60};
    int i,j;
    
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("a[%d][%d] = %d\n",i,j,a[i][j]);
        }
    }
    
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("&a[%d][%d] = %p,(a[%d]+%d]) = %p\n",i,j,&a[i][j],i,j,a[i]+j);
        }
    }
    
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("&a[%d][%d] = %p,(*(a+%d)+%d) = %p\n",
                i,j,&a[i][j],
                i,j,*(a+i)+j);
        }
    }
    
    return 0;
}