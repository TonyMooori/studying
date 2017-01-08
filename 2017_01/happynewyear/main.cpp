#include <iostream>
#include <string>

using namespace std;

// 2進数で表された画像を文字絵列に変換する関数
string to_str(int32_t n){
    string ret;
    for(int i=0 ; i < 25 ; i++ ){
        ret += n % 2 == 0 ?' ':'*';
        ret += i%5==4 ? "\n" : "";
        n>>=1;
    }
    return ret;
}

int main(void){
    // 5x5ピクセルの文字の画像を2進数で表した数字，"HAPY NEWR"の順番
    int32_t imgs[] = {18415153,18415167,1558063,4336177,0,18667121,32570431,11195953,18335279};
    // 9進数で"HAPPY NEW YEAR"の要素番号が出て来るマジックナンバー
    int64_t n = 20817985495500L;
    
    while(n){
        // うぇーい
        cout << to_str(imgs[n % 9]) << endl;
        n /= 9;
    }
    return 0;
}
