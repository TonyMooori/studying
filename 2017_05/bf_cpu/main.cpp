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

int main(void){
    char code[] = ">+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.[-]>++++++++[<++++>-]<.>+++++++++++[<+++++>-]<.>++++++++[<+++>-]<.+++.------.--------.[-]>++++++++[<++++>-]<+.[-]++++++++++.+[]";
    int buff[65536]={0};
    int ra=0;
    int rb=0;
    int rc=0;
    int rd=0;
    
    while(true){
        if( rd == 0 ){
            //cout << "now " << code[rc] << endl;
            if( code[rc] == '>' ){
                ra++;
                rb=rand();
                rc++;
                rd=0;
            }else if( code[rc] == '<' ){
                ra--;
                rb=rand();
                rc++;
                rd=0;
            }else if( code[rc] == '+' ){
                buff[ra]++;
                
                ra+=0;
                rb=rand();
                rc++;
                rd=0;
            }else if( code[rc] == '-' ){
                buff[ra]--;
                
                ra+=0;
                rb=rand();
                rc++;
                rd=0;
            }else if( code[rc] == '.' ){
                putchar(buff[ra]);
                
                ra+=0;
                rb=rand();
                rc++;
                rd=0;
            }else if( code[rc] == ',' ){
                // ?
                
                ra+=0;
                rb=rand();
                rc++;
                rd=0;
            }else if( code[rc] == '[' && buff[ra] == 0 ){
                ra+=0;
                rb=1;
                rc++;
                rd=1;
            }else if( code[rc] == '[' && buff[ra] != 0 ){
                ra+=0;
                rb=rand();
                rc++;
                rd=0;
            }else if( code[rc] == ']' ){
                ra+=0;
                rb=1;
                rc--;
                rd=2;
            }
        }else if( rb != 0 && rd == 1){
            if( code[rc] == '[' ){
                ra+=0;
                rb++;
                rc++;
                rd=1;
            }else if( code[rc] == ']' ){
                ra+=0;
                rb--;
                rc++;
                rd=1;
            }else {
                ra+=0;
                rb+=0;
                rc++;
                rd=1;
            }
        }else if( rb == 0 && rd == 1){
            ra+=0;
            rb=rand();
            rc+=0;
            rd = 0;
        }else if( rb != 0 && rd == 2 ){
            if( code[rc] == '[' ){
                ra+=0;
                rb--;
                rc--;
                rd=2;
            }else if( code[rc] == ']' ){
                ra+=0;
                rb++;
                rc--;
                rd=2;
            }else {
                ra+=0;
                rb+=0;
                rc--;
                rd=2;
            }
        }else if( rb == 0 && rd == 2 ){
            ra+=0;
            rb=rand();
            rc++;
            rd = 0;
        }
    }
    
    return 0;
}












