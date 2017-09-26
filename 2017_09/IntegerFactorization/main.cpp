#include <iostream>
#include <cstdlib>

using namespace std;

uint64_t gcd(uint64_t a,uint64_t b){
	uint64_t temp;
	if( b<a )return gcd(b,a);
	temp = b%a;
	if( temp == 0 )return a;
	return gcd(temp,a);
}

uint64_t f(uint64_t n){
    uint64_t ret = rand();
    
    for(int i = 0 ; i < 4 ; i++ ){
        ret = ret << 15;
        ret = ret + rand();
    }
    return ret%n;
}
// https://ja.wikipedia.org/wiki/ポラード・ロー素因数分解法



int main(void){
//	cout << gcd(17*64,25*4) << endl;
//	cout << RAND_MIN << endl;
	uint64_t x,y,d,temp,n;
	n=(uint64_t)2462401*2462401;

	do{
		x = 2;
		y = 2;
		d = 1;
	

		while(d==1){
			x = f(n);
			y = f(f(n));
			d = gcd(max(x,y)-min(x,y),n);
		}

	}while(d==n);
	cout << d << endl;
	

	return 0;
}

