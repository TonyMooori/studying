#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>

#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;

#define N 8

#define B       -1
#define ZERO    0
#define ONE     1
#define M       2

typedef enum _motion_t{
    LEFT,
    RIGHT,
    NONE
} motion_t;

typedef struct _command{
    int current_tape;
    int next_tape;
    string current_head;
    string next_head;
    motion_t motion;
} command_t;

int main(void){
    int tape[N];
    vector< command_t > cmds;
    string head = "start";
    int head_at = 0;
    srand(1);
    
    // 初期化
    REP(i,N)tape[i]=B;
    
    // 代入
    tape[0] = B;
    FOR(i,1,N-2)
        tape[i] = rand() % 2;
    tape[N-2] = M;
    tape[N-1] = B;
    
    
    //                        now tape/next tape/now head/next head/motion/
    cmds.push_back( (command_t){    B ,    B , "start"  , "pick"  , RIGHT });
    
    cmds.push_back( (command_t){ ZERO ,    B , "pick"   , "pick0" , RIGHT });
    cmds.push_back( (command_t){  ONE ,    B , "pick"   , "pick1" , RIGHT });
    cmds.push_back( (command_t){    M ,    M , "pick"   , "fin" , RIGHT });
    
    cmds.push_back( (command_t){ ZERO , ZERO , "pick0" , "pick0" , RIGHT });
    cmds.push_back( (command_t){  ONE ,  ONE , "pick0" , "pick0" , RIGHT });
    cmds.push_back( (command_t){    M , ZERO , "pick0" , "moveM" , LEFT });
    
    cmds.push_back( (command_t){ ZERO , ZERO , "pick1" , "pick1" , RIGHT });
    cmds.push_back( (command_t){  ONE ,  ONE , "pick1" , "pick1" , RIGHT });
    cmds.push_back( (command_t){    M ,  ONE , "pick1" , "moveM" , LEFT });
    
    cmds.push_back( (command_t){ ZERO ,    M , "moveM" , "move0" , LEFT });
    cmds.push_back( (command_t){  ONE ,    M , "moveM" , "move1" , LEFT });
    cmds.push_back( (command_t){    B ,    M , "moveM" , "toB"  , LEFT });
    
    cmds.push_back( (command_t){ ZERO , ZERO , "move0" , "move0" , LEFT });
    cmds.push_back( (command_t){  ONE , ZERO , "move0" , "move1" , LEFT });
    cmds.push_back( (command_t){    B , ZERO , "move0" , "toB"  , LEFT });
    
    cmds.push_back( (command_t){ ZERO ,  ONE , "move1" , "move0" , LEFT });
    cmds.push_back( (command_t){  ONE ,  ONE , "move1" , "move1" , LEFT });
    cmds.push_back( (command_t){    B ,  ONE , "move1" , "toB"  , LEFT });
    
    cmds.push_back( (command_t){ ZERO , ZERO ,  "toB" , "move0" , LEFT });
    cmds.push_back( (command_t){  ONE ,  ONE ,  "toB" , "move1" , LEFT });
    cmds.push_back( (command_t){    B ,    B ,  "toB" , "pick"  , RIGHT });
    
    while(head != "fin"){
        int current_tape = tape[head_at];
        
        REP(i,cmds.size()){
            command_t cmd = cmds[i];
            if( cmd.current_head == head 
                && cmd.current_tape == current_tape ){
                
                tape[head_at] = cmd.next_tape;
                head_at += cmd.motion == LEFT ? -1 : (cmd.motion == RIGHT ? 1 : 0 );
                head = cmd.next_head;
                break;
            }
        }
        
        cout << "head = " << head << endl;
        REP(i,N){
            cout << " ";
            switch( tape[i] ){
                case ZERO:
                    cout << 0;
                    break;
                case ONE:
                    cout << 1;
                    break;
                case M:
                    cout << "M";
                    break;
                case B:
                    cout << "B";
                    break;
            }
            cout << " ";
        }
        cout << endl;
        
        REP(i,N){
            if( i == head_at )
                cout << " I ";
            else
                cout << "   ";
        }
        cout << endl;
    }
    
    
    
    return 0;
}

