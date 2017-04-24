#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]){
    int val=5;
    char buffer_one[15];
    char buffer_two[8];
    
    if( argc<2 ){
        printf("error: No command line arguments.\n");
        return 0;
    }
    
    strcpy(buffer_one,"one");
    strcpy(buffer_two,"two");
    printf("val       : ptr=%p, value=%d(%p)\n",&val,val,val);
    printf("buffer_one: ptr=%p, value=%s\n",buffer_one,buffer_one);
    printf("buffer_two: ptr=%p, value=%s\n",buffer_two,buffer_two);
    
    printf("\ncopy %d bytes data to buffer_two\n\n",strlen(argv[1]));
    strcpy(buffer_two,argv[1]);
    
    printf("val       : ptr=%p, value=%d(%p)\n",&val,val,val);
    printf("buffer_one: ptr=%p, value=%s\n",buffer_one,buffer_one);
    printf("buffer_two: ptr=%p, value=%s\n",buffer_two,buffer_two);
    
    
    return 0;
}
