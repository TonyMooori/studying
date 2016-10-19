#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t


int main(void){
    int n;
    vector<int> a;
    int ret = 0;
    
    cin >> n;
    for(int i = 0 ; i < n ; i++ ){
        int temp = 0;
        cin >> temp;
        a.push_back(temp);
    }
    
    
    for(int i = 0 ; i < a.size() ; i++ ){
    for(int j = i+1 ; j < a.size() ; j++ ){
    for(int k = j+1 ; k < a.size() ; k++ ){
        int A = max(a[i],max(a[j],a[k]));
        int sum = a[i]+a[j]+a[k];
        
        if( 2*A < sum ) {
            ret = max(ret,sum);
        }
    }
    }
    }
    
    cout << ret;
    
    return 0;
}
