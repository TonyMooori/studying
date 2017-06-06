#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <stack>
#include <ctime>

#ifndef _USEFUL_MACROS_
#define _USEFUL_MACROS_
#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#endif 

#define TYPE_INTEGER    0   // integer
#define TYPE_FLOAT      1   // float
#define TYPE_STRING     2   // string
#define TYPE_IDENT      3   // identification
#define TYPE_NIL        4   // nil
#define TYPE_TRUE       5   // t(true)


using namespace std;

int main(void){
    string s;
    char temp_str[2] = "0";
    map<char,int> op_rank;
    stack<char> op_stack;
    int n=0;
    
    op_rank['+'] = 1;
    op_rank['-'] = 1;
    op_rank['*'] = 2;
    op_rank['/'] = 2;
    op_rank['('] = 0;
    op_rank[')'] = 0;
    
    cin >> s;
    s=s+")";
    op_stack.push('(');
    
    REP(i,s.size()){
        if( isdigit(s[i])){
            temp_str[0] = s[i];
            n = 10 * n + atoi(temp_str);
        }else{
            cout << n << " ";
            n = 0;
            while( op_stack.size() ){
                if( op_rank[op_stack.top()] >= op_rank[s[i]] ){
                    if( op_rank[op_stack.top()] != 0 )
                        cout << op_stack.top() << " ";
                    op_stack.pop();
                }else{
                    break;
                }
            }
            op_stack.push(s[i]);
        }
    }
    
    return 0;
}
