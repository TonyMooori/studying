#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t


int main(void){
    int L,n;
    vector<int> x;
    int M = INT_MIN;
    int m = INT_MIN;
    
    cin >> L;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++ ){
        int temp;
        cin >> temp;
        x.push_back(temp);
    }
    
    for(int i = 0 ; i < n ; i++ ){
        M = max( M , max(x[i],L - x[i] ));
        m = max( m , min(x[i],L-x[i]));
        
        
    }
    cout << "min = "<< m << endl;
    cout << "max = "<< M << endl;
    
    
    return 0;
}
