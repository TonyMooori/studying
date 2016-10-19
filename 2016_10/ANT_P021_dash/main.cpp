#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t


int main(void){
    int n;
    vector<int> a;
    
    cin >> n;
    for(int i = 0 ; i < n ; i++ ){
        int temp = 0;
        cin >> temp;
        a.push_back(temp);
    }
    
    sort(a.begin() , a.end() );
    reverse(a.begin(),a.end() );
    
    
    for(int i = 0 ; i < a.size() - 2 ; i++ ){
        int A = a[i];
        int BC = a[i+1] + a[i+2];
        
        if( A < BC ){
            cout << A + BC << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
