//#include "CppUTest/CommandLineTestRunner.h"
#include <iostream>
#include <string.h>

#include <cstdio>
#include <cmath>
#ifndef _USEFUL_MACROS_
#define _USEFUL_MACROS_
#define INF 99999999
#define N_PRIME 1000000007
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define OUTPUT_DEBUG
#ifdef OUTPUT_DEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x) do{}while(false)
#endif
#endif 


using namespace std;


const float L_1 = 0.20;
const float L_2 = 0.20;
const float L_3 = 0.40;



// 連立線形方程式を解く
template<int N>
void solve(const float M[N][N], float x[N], const float b[N])
{
  float A[N][N];
  float B[N];
  float temp;

  // コピー
  for (int i = 0 ; i < N ; i++ ) {
    B[i] = b[i];
    for (int j = 0 ; j < N ; j++ ) {
      A[i][j] = M[i][j];
    }
  }
  for (int i = 0 ; i < N ; i++ ) {
    // ピボット選択
    for (int j = i + 1 ; j < N ; j++ ) {
      if ( fabs(A[i][j]) >= 1e-8f )
        break;

      for (int k = 0 ; k < N ; k++ )
        A[i][k] += A[j][k];
      B[i] += B[j];
    }

    // 対角成分を1に
    temp = A[i][i];
    for (int j = i ; j < N ; j++ )
      A[i][j] /= temp;
    B[i] /= temp;

    // 前進消去
    for (int j = i + 1 ; j < N ; j++ ) {
      temp = A[j][i];

      for (int k = i ; k < N ; k++ )
        A[j][k] -= temp * A[i][k];
      B[j] -= temp * B[i];
    }
  }

  // 後進消去
  for (int i = N - 1 ; i >= 0 ; i-- ) {
    for (int j = i - 1 ; j >= 0 ; j-- ) {
      B[j] -= A[j][i] * B[i];
    }
  }

  for (int i = 0 ; i < N ; i++ )
    x[i] = B[i];
}

float Judge(const float targets[6],const float *rets){
  float y[6];
  
  const float Tr = rets[0];
  const float Tl = rets[1];
  const float Tb = rets[2];
  const float theta_f = rets[3];
  const float theta_p = rets[3];
  const float theta_y = rets[4];

  const float sin_theta_f = sin(theta_f);
  const float cos_theta_f = cos(theta_f);
  const float sin_theta_p = sin(theta_p);
  const float cos_theta_p = cos(theta_p);
  const float sin_theta_y = sin(theta_y);
  const float cos_theta_y = cos(theta_y);

  y[0] = -L_2 * sin_theta_f * Tr + L_2 * sin_theta_f * Tl;
  y[1] =  L_1 * sin_theta_f * Tr + L_1 * sin_theta_f * Tl - L_3 * sin_theta_p * cos_theta_y * Tb;
  y[2] = -L_2 * cos_theta_f * Tr + L_2 * cos_theta_f * Tl -               L_3 * sin_theta_y * Tb;
  y[3] =        cos_theta_f * Tr +       cos_theta_f * Tl +       cos_theta_p * cos_theta_y * Tb;
  y[4] =                                                                        sin_theta_y * Tb;
  y[5] =       -sin_theta_f * Tr -       sin_theta_f * Tl -       sin_theta_p * cos_theta_y * Tb;

  float evaluate = 0;
  
  for(int i = 0 ; i < 6 ; i++ ){
    const float subs = targets[i] - y[i];
    evaluate += subs * subs;
  }
  
  return evaluate;
}

void calculate_rets(const float target_P, const float target_Q, const float target_R, const float target_X, const float target_Z, float *rets) {
    const float eps = 1e-4;
    const float targets[6] = { target_P, target_Q, target_R , target_X, 0 , target_Z };
    const float normalize[5] = {1000,1000,1000,M_PI/2,M_PI/4};
    float hessian[5][5];
    float diff[5];
    float J1s[5];
    float hessian_inv[5][5];
    float step[5];
    float lr = 0.01;
    
    // http://dsl4.eee.u-ryukyu.ac.jp/DOCS/nlp/node5.html
    // 勾配
    const float J00 = Judge(targets, rets);
    for(int i = 0 ; i < 5 ; i++ ){
        rets[i] += eps*normalize[i];
        J1s[i] = Judge(targets,rets);
        rets[i] -= eps*normalize[i];
        diff[i] = (J1s[i] - J00)/eps/normalize[i];
        cout << "diff[i]="<<diff[i]<<endl;
    }
    
    // ヘシアン
    for(int i = 0 ; i < 5 ; i++ ){
        for(int j = i ; j < 5 ; j++ ){
            rets[j] += eps * normalize[j];
            rets[i] += eps * normalize[i];
            const float J11 = Judge(targets, rets);
            rets[j] -= eps * normalize[j];
            rets[i] -= eps * normalize[i];
            hessian[i][j] = (J11-J1s[i]-J1s[j]+J00)/eps/eps/normalize[i]/normalize[j];
            hessian[j][i] = hessian[i][j];
            //cout << hessian[i][j] << endl;
        }
    }

    // ヘシアンの逆行列
    for (int i = 0 ; i < 5 ; i++ ) {
        float b[5] = {0};
        float x[5];
        b[i] = 1;
        solve<5>(hessian,x,b);
        
        for(int j = 0 ; j < 5 ; j++ )
            hessian_inv[j][i] = x[j];
    }
    
    // ステップ幅の球解
    for(int i = 0 ; i < 5 ; i++ ){
        step[i]=0;
        for(int j = 0 ; j < 5 ; j++ ){
            step[i]+=hessian_inv[i][j]*diff[i];
        }
        rets[i]-=lr*normalize[i]*step[i];
    }
    
  
}

/*
114.043
105.865
10.7235
0.780629
-0.935819
*/

int main(){
    const float target_P = -1.15;
    const float target_Q = 29.28;
    const float target_R = 2.29;
    const float target_X = 160.00;
    const float target_Z = -160.00;


    float rets[5];
    
    rets[0] = target_X/3-target_Z/3;
    rets[1] = target_X/3-target_Z/3;
    rets[2] = target_X/3-target_Z/3;
    rets[3] = M_PI/3;
    rets[4] = -0.1;
    
    REP(j,20){
        calculate_rets(target_P, target_Q, target_R, target_X, target_Z, rets);
        REP(i,5)
            cout << rets[i] << endl;
            
        cout<<"-------------"<<endl;
    }
    
    
    return 0;
}
