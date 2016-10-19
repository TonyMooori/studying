#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t

int main(void){
    int n;
    vector<int> a;
    int k;
    
    cin >> n;
    for(int i = 0 ; i < n ; i++ ){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cin >> k;
    for(int i = 0 ; i < (1<<n) ; i++ ){
        int temp = i;
        int sum = 0;
        //cout << "---" << i << endl;
        for(int j = 0 ; j < n ; j++ ){
            sum += (temp%2) * a[j];
            temp /= 2;
        }
        //cout <<sum<<endl;
        if( sum == k ){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout <<"No" << endl;
    return 0;
}