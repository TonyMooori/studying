
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;

#define N 32768

// the chunk of bf command
typedef struct _command{
    char c;
    uint8_t n_command;
    int pair_index;
} command;

bool one_of(const string list,const char target);
vector<command> analyze(const string code);
void eval(const vector<command> code);

int main(int argc,char *argv[]){
    FILE *fp;
    char c;
    string code;
    
    if( argc <= 1 ){
        cout << "Error: No argument of file path.";
        exit(0);
    }
    
    fp = fopen( argv[1] , "r" );
    if( fp == NULL ){
        cout << "Error: File not found.";
        exit(0);
    }
    
    // read source code
    while((c = fgetc(fp)) != EOF )
        code += c;
    fclose(fp);
    
    // analyze source code
    auto temp = analyze(code);
    
    // evaluate
    eval(temp);
    
    return 0;
}

void eval(const vector<command> code){
    int at = 0;                 // index of memory
    uint8_t memory[N];
    REP(i,N)memory[i] = 0;
    
    REP(i,code.size()){
        if( code[i].c == '>' ){
            at+=code[i].n_command;
        }else if( code[i].c == '<' ){
            at-=code[i].n_command;
        }else if( code[i].c == '+' ){
            memory[at]+=code[i].n_command;
        }else if( code[i].c == '-' ){
            memory[at]-=code[i].n_command;
        }else if( code[i].c == '.' ){
            REP(j,code[i].n_command )
                putchar(memory[at]);
        }else if( code[i].c == ',' ){
            REP(j,code[i].n_command)
                memory[at] = getchar();
        }else if( code[i].c == '[' ){
            if( memory[at] == 0)
                i = code[i].pair_index; // skip to "]"
        }else if( code[i].c == ']' ){
            i = code[i].pair_index - 1; // return to "["
        }
    }
}

vector<command> analyze(const string code){
    vector<command> ret;
    command cmd;
    stack<int> index_stack;
    
    REP(i,code.size()){
        // ignore other character
        if( one_of("+-><.,[]",code[i]) == false )
            continue;
        
        // initialize
        cmd.c = code[i];
        cmd.pair_index = 0;
        cmd.n_command = 0;
        
        if( one_of("+-><.,",code[i]) ){
            // count same character
            cmd.n_command = 0;
            while( i < code.size() ){
                if( code[i] == cmd.c ){
                    cmd.n_command++;
                }else{
                    i--;
                    break;
                }
                i++;
            }
        }else{
            cmd.n_command = 1;
        }
        
        ret.push_back(cmd);
    }
    
    // search the pair of ([,])
    // save the each other of index
    REP(i,ret.size()){
        if( ret[i].c == '[' ){
            index_stack.push(i);
        }else if( ret[i].c == ']' ){
            if( index_stack.size() == 0 )
                continue;
            
            int temp = index_stack.top();   // index of "["
            index_stack.pop();
            ret[i].pair_index = temp;
            ret[temp].pair_index = i;
        }
    }
    return ret;
}


bool one_of(const string list,const char target){
    REP(i,list.size())
        if( target == list[i] )
            return true;
    return false;
}