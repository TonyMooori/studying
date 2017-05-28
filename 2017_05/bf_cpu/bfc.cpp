#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#ifndef _USEFUL_MACROS_
#define _USEFUL_MACROS_
#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#endif 

using namespace std;

int main(int argv,char *argc[]){
    FILE *src;
    FILE *output;
    char c;
    
    if( argv <= 2 ){
        cout << "Error: no input file." << endl;
        cout << "usage: ./bfc code.txt out.txt" << endl;
        return 0;
    }
    
    src = fopen(argc[1],"r");
    if( src == NULL ){
        cout << "File \"" << argc[1] << "\" not foud." << endl;
        return 0;
    }
    
    output = fopen(argc[2],"w");
    if( output == NULL ){
        cout << "File \"" << argc[2] << "\" not foud." << endl;
        return 0;
    }
    
    fprintf(output,"v2.0 raw\n");
    while( (c=fgetc(src)) != EOF ){
        int n = -1;
        char codes[9] = "><+-.,[]";
        
        REP(i,8)
            if( codes[i] == c )
                n = i;
        
        if( n != -1 ){
            fprintf(output,"%d ",n);
        }
    }
    
    
    fclose(src);
    fclose(output);
    
    return 0;
}












