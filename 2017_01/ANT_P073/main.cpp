#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;

int main(void){
    
    int N,L,P;
    cin >> N >> L >> P;
    vector<int> A(N+1),B(N+1);
    
    REP(i,N)
        cin >> A[i];
    REP(i,N)
        cin >> B[i];
    A[N] = L;
    B[N] = 0;
    
    /*
    トラックで距離L
    P最初ガソリンある
    場所A[i]でB[i]だけガソリン貯めれる
    */
    int pos = 0;    // 現在地
    int tank = P;   // ガソリン
    priority_queue<int> q;
    int count = 0;
    
    REP(i,N+1){
        int dist = A[i] - pos;
        
        // 足りないとき
        while( dist > tank ){
            if( q.empty() == true ){
                // なかったらミッション失敗
                cout << -1 << endl;
                return 0;
            }else{
                // 足りるまで貯める
                tank += q.top();
                q.pop();
                count++;
            }
        }
        
        tank -= dist;
        q.push( B[i] );
        pos = A[i];
    }
    
    cout << count << endl;
    
    return 0;
}
