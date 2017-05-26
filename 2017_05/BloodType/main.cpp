#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdlib>

#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;

#define N_TYPE 6
#define N_GENERATION 1000

int make_child(int mother,int father){
    int arr[4] = {
        mother / 3,
        mother % 3,
        father / 3,
        father % 3
    };
    
    
    REP(j,4){
        int a = rand()%4;
        int b = rand()%4;
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    
    return max(arr[0],arr[1])*3+min(arr[0],arr[1]);
}

int main(void){
    const int N=100000;
    vector<int> humans;
    /*
    AA,AB,AO,BO,OO
    A=2,B=1,O=0
    val = left * 3 + right;(left>=right)
    */
    const double rates[N_TYPE] = {
        0.23,    // AA    2*3+2=8
        0.15,    // AB    2*3+1=7
        0.06,    // BB    1*3+1=4
        0.17,    // BO    1*3+0=3
        0.29,    // OO    0*3+0=0
        0.10,    // AO    2*3+0=6
    };
    const int types[N_TYPE] = {
        8,  // AA
        7,  // AB
        4,  // BB
        3,  // BO
        0,  // OO
        6,  // AO
    };
    const int get_idx[9] = {
         4, // 0:OO
        -1, // 1:--
        -1, // 2:--
         3, // 3:BO
         2, // 4:BB
        -1, // 5:--
         5, // 6:AO
         1, // 7:AB
         0  // 8:AA
    };
    const string names[N_TYPE] = {
        "AA",
        "AB",
        "BB",
        "BO",
        "OO",
        "AO",
    };
    
    srand(1);
    
    REP(i,N_TYPE){
        REP(j,N*rates[i]){
            humans.push_back(types[i]);
        }
    }
    
    //************* header *************
    cout << "gen";
    REP(i,N_TYPE)
        cout<<","<<names[i];
    cout << endl;
    //************* header *************
    
    REP(gen,N_GENERATION){
        // 現在の人口
        int now_humans = humans.size();
        int sums[N_TYPE] = {0,0,0,0,0,0};
        random_shuffle(humans.begin(), humans.end());
        
        REP(i,now_humans/2){
            int mother = humans[2*i];
            int father = humans[2*i+1];
            
            sums[get_idx[mother]]++;
            sums[get_idx[mother]]++;
            
            int ch1 = make_child(mother,father);
            int ch2 = make_child(mother,father);
            
            humans[2*i] = ch1;
            humans[2*i+1] = ch2;
        }
        
        /*
        cout << "GENERATION : " << gen << endl;
        REP(i,5){
            cout << names[i] << " : " << (sums[i]) << "percent" << endl;
        }
        */
        cout << gen;
        REP(i,N_TYPE)
            cout << "," << ((double)sums[i]/now_humans);
        cout << endl;
    }
    
    return 0;
}
