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

typedef int SEISU;

SEISU main(void){
    SEISU n;
    
    for(n=0;n<10;n++)
        printf("%d\n",n);
    
    return 0;
}
