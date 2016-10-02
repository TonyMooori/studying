#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <cmath>
#include <cstdio>

#define N_DATA      128
#define MAX_NOISE   1e-1
#define N_WEIGHT    12

// g++ -o main main.cpp -I E:\dev\Eigen-3.2.8\
// ↓ここが一番幸せ
// https://eigen.tuxfamily.org/dox/group__QuickRefPage.html


using namespace std;
using namespace Eigen;

// 線形回帰で結果を見てみる
VectorXd linear_reg(VectorXd weight, double x_min, double x_max );
// 線形回帰分析で重みを計算する(基底関数は多項式)
VectorXd fit(VectorXd xs,VectorXd ys);
// 保存する
void save_file(VectorXd ys_predict);

int main(void){
    VectorXd xs,ys,weight,ys_predict;
    
    xs = VectorXd::Random(N_DATA);                      // N_DATA個の (-1,1) の一様乱数を生成
    xs *= M_PI;                                         // 範囲を(-PI,PI)のデータに
    ys = xs.array().sin();                              // xsのsinをysに
    ys += VectorXd::Random(N_DATA)*MAX_NOISE;           // ノイズを加える
    
    weight = fit(xs,ys);                                // 回帰分析
    ys_predict = linear_reg(weight,-M_PI,M_PI);         // 実際に計算してみる
    save_file(ys_predict);                              // ファイルに出力
    
    return 0;
}

// 線形回帰で結果を見てみる
VectorXd fit(VectorXd xs,VectorXd ys){
    // とりあえず正則化項なし，バイアス項なしでx ** N_WEIGHTまでの基底関数で
    VectorXd xs_temp = xs;
    MatrixXd A(N_DATA,N_WEIGHT);
    
    for(int i = 0 ; i < N_WEIGHT ; i++ ){
        A.col(i) = xs_temp;
        xs_temp = xs.cwiseProduct(xs_temp);
    }
    
    // solve( A.T.dot(A) , A.T.dot(ys))
    return (A.transpose()*A).colPivHouseholderQr().solve(A.transpose()*ys);
}

// 線形回帰で結果を見てみる
VectorXd linear_reg(VectorXd weight, double x_min, double x_max ){
    VectorXd xs = VectorXd::LinSpaced( Sequential, N_DATA, x_min, x_max);
    VectorXd xs_temp = xs;
    VectorXd ys = VectorXd::Zero(N_DATA);
    
    // バイアスなんてなかった，いいね？
    // ys = ys + weight[0]; // 
    for(int i = 0 ; i < N_WEIGHT ; i++ ){
        ys += weight[i] * xs_temp;                  // w[i] * x**(1+i)
        xs_temp = xs.cwiseProduct(xs_temp);         // アダマール積はこう！
    }
    
    return ys;
}

// データを出力
void save_file(VectorXd ys_predict){
    char filename[32];
    FILE *fp;
    VectorXd xs = VectorXd::LinSpaced( Sequential, N_DATA, -M_PI,M_PI);
    
    sprintf(filename,"DATA_%d_WEIGHT_%d.csv",N_DATA,N_WEIGHT);
    
    fp = fopen(filename,"w");
    if( fp == NULL) exit(0);
    
    // 出力する
    fprintf(fp,"x,y\n");
    for(int i = 0 ; i < N_DATA ; i++ ){
        fprintf(fp,"%lf,%lf\n",xs[i],ys_predict[i]);
    }
    
    fclose(fp);
}