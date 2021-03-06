/* 二重振り子のシミュレーションプログラム
 * 式の導出は諦めたので以下のサイトを参考にしました
 *
 * 2重振り子 http://www.aihara.co.jp/~taiji/pendula-equations/present-node2.html
 */
 

int FRAME_RATE = 60;
int SPEED = 10;
float t;
float dt = (float)(1.0 / FRAME_RATE)*SPEED;
float[] theta;            //theta1,theta1_dot,theta2,theta2_dot
//FloatList[] theta_list;

// パラメーター
float l1 = 100;
float l2 = 100;
float m1 = 10;
float m2 = 1;
float g = 9.8;

float m12 = m1+m2;

void setup() {
  size(640, 480);
  frameRate(FRAME_RATE);

  init_var();
}

void init_var() {
  // 初期値代入
  theta = new float[4];
  theta[0] = PI-1.0e2;
  theta[1] = 0;
  theta[2] = PI+1.0e2;
  theta[3] = 0;

  // theta1,theta2の履歴を保存
  //theta_list = new FloatList[2];
  //for (int i = 0; i < 2; i++ )
  //  theta_list[i] = new FloatList();
}

void draw() {
  // 表示設定
  background(0);
  stroke(0, 255, 0);
  translate(width/2, height/2);
  strokeWeight(5);

  // 計算
  t += dt;
  theta = RK(dt, theta, t);

  // 履歴を残す
  //theta_list[0].append(theta[0]);
  //theta_list[1].append(theta[2]);

  // 描画
  float x1 = l1*sin(theta[0]);
  float y1 = l1*cos(theta[0]);
  float x2 = l1*sin(theta[0]) + l2*sin(theta[2]);
  float y2 = l1*cos(theta[0]) + l2*cos(theta[2]);
  line(0, 0, x1, y1);
  line(x1, y1, x2, y2);

  // 画面保存
  //saveFrame("./frame/####.png");
}

float[] RK(float dt, float[] x, float t) {
  // ルンゲクッタ法で微分方程式を解く関数

  // dt * dx(t_n,x_n)
  float[] dx_k1 = sv_mul(dt, dx(t, x));

  // dt * (dx(t_(n+0.5),x_(n+0.5))
  float[] dx_k2 = sv_mul(dt, dx(t+dt/2.0, vv_add(x, sv_mul(0.5, dx_k1))));

  // dt * (dx(t_(n+0.5),x_(n+0.5))
  float[] dx_k3 = sv_mul(dt, dx(t+dt/2.0, vv_add(x, sv_mul(0.5, dx_k2))));

  // dt * (dx(t_(n+1),x_(n+1))
  float[] dx_k4 = sv_mul(dt, dx(t+dt, vv_add(x, dx_k3)));

  // 足す
  x = vv_add(x, sv_mul(1.0/6.0, dx_k1));
  x = vv_add(x, sv_mul(2.0/6.0, dx_k2));
  x = vv_add(x, sv_mul(2.0/6.0, dx_k3));
  x = vv_add(x, sv_mul(1.0/6.0, dx_k4));

  return x;
}

float[] dx(float t, float[] x) {
  // 関数xを微分したもの

  // 微分した値
  float[] ret = new float[x.length];

  // 長くなるので少しまとめておく
  float S = sin(x[0]-x[2]);
  float C = cos(x[0]-x[2]);
  float t1 = x[0];    // theta1
  float t1_d = x[1];  // theta1 dot
  float t2 = x[2];    // theta2
  float t2_d = x[3];  // theta2 dot

  ret[0] = t1_d;
  ret[1] = (g*(sin(t2)*C-m12/m2*sin(t1))-(l1*t1_d*t1_d*C+l2*t2_d*t2_d)*S)/(l1*(m12/m2-C*C));
  ret[2] = t2_d;
  ret[3] = (g*m12/m2*(C*sin(t1)-sin(t2))+(m12/m2*l1*t1_d*t1_d+l2*t2_d*t2_d*C)*S)/(l2*(m12/m2-C*C));

  return ret;
}

float[] sv_mul(float s, float[] v) {
  // ベクトルとスカラーの積を計算する関数
  float[] ret = new float[v.length];

  for (int i = 0; i < v.length; i++ )
    ret[i] = v[i] * s;

  return ret;
}

float[] sv_add(float s, float[] v) {
  // ベクトルとスカラーの和を計算する関数
  float[] ret = new float[v.length];

  for (int i = 0; i < v.length; i++ )
    ret[i] = v[i] + s;

  return ret;
}

float[] vv_add(float[] v1, float[] v2) {
  // ベクトルとベクトルの和を計算する関数
  float[] ret = new float[v1.length];

  for (int i = 0; i < v1.length; i++ )
    ret[i] = v1[i] + v2[i];

  return ret;
}