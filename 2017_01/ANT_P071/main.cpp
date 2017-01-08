#include <iostream>
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

#define MAX_N 100

/*
           0
     1           2
  3    4      5     6
 7 8  9 10  11 12 13 14

自分の番号は index
親は (index-1) / 2
子供は index*2+1とindex*2+2
*/

class Heap{
public:
    Heap(int n){
        _n = n;
        _heap = (int*)malloc(n*sizeof(int));
        _size = 0;
        REP(i,n)
            _heap[i] = INF;
    }
    ~Heap(){
        free(_heap);
    }
    
    void push(int x){
        int index = _size;
        _size++;
        
        while(index>0){
            // 親の番号
            int parent = (index-1)/2;
            
            if( _heap[parent] <= x )break;
            
            _heap[index] = _heap[parent];
            index = parent;
        }
        _heap[index] = x;
    }
    
    int pop(){
        int ret = _heap[0];  // 最小値
        _size--;
        int x = _heap[_size];
        int index = 0;
        
        while( index*2+1 <_size ){
            int child1 = index * 2 + 1;
            int child2 = index * 2 + 2;
            
            if ( child2 < _size && _heap[child2] < _heap[child1] )
                child1 = child2;    // child1を小さい方の数にする
            
            if( _heap[child1] >= x )break;
            
            _heap[index] = _heap[child1];
            index = child1;
        }
        
        _heap[index]=x;
        
        return ret;
    }
    
    int _size;
    int _n;
    int *_heap;
};

int main(void){
    Heap heap(100);
    
    while(true){
        int temp;
        cin >> temp;
        
        if( temp == 0 )break;
        
        heap.push(temp);
    }
    
    while( heap._size != 0 )
        cout << heap.pop() << endl;
    
    return 0;
}
