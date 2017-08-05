float input;      // 入力(外乱みたいな感じ)
float old_time;   // 1個前のループ実行時の時間[s]

Mat x_now=new Mat(4, 1);  // 制御対象の状態変数
Mat x_est=new Mat(4, 1);  // オブザーバが推定した状態変数

void setup() {
  set_params();  // パラメータの代入とかする

  old_time = millis()/1000.0f;
  size(640, 540);
}

void draw() {
  float x, theta;

  background(0);
  strokeWeight(5);
  fill(0);
  translate(width/2, height/2);

  // x_est,x_nowの更新
  simulation();

  // 制御対象の描画
  x=x_now.data[0][0];
  theta=x_now.data[2][0];
  stroke(255);
  translate(0, -75);
  rect(x*100-40, -25, 80, 50);
  line(x*100, 0, x*100+100*sin(theta), -100*cos(theta));

  // オブザーバの値を可視化したもの
  x = x_est.data[0][0];
  theta = x_est.data[2][0];
  translate(0, 200);
  rect(x*100-40, -25, 80, 50);
  line(x*100, 0, x*100+100*sin(theta), -100*cos(theta));
  
  //saveFrame("./frames/####.png");
}

void simulation() {
  float t = millis()/1000.0f;
  float dt = t - old_time;
  old_time = t;

  Mat u=new Mat(1, 1);    // 入力u
  Mat u_y=new Mat(3, 1);  // オブザーバにあたえるデータ入力uと出力y

  try {
    // 入力uはフィードバックゲインとオブザーバの推定値を掛けたもの
    u = MatOp.mprod(K_mat, x_est);
    u.data[0][0]+=input;

    // オブザーバにあたえるパラメータは入力uと出力y
    // 出力yはx,thetaのみ与える
    u_y.data[0][0] = u.data[0][0];
    u_y.data[1][0] = x_now.data[0][0];
    u_y.data[2][0] = x_now.data[2][0];

    // 制御対象のシミュレーション(非線形方程式)
    x_now = sim.step(x_now, t, dt, u );
    // オブザーバのシミュレーション(線形方程式)
    x_est = observer.step(x_est, t, dt, u_y);

    //disp(x_now);
    //disp(x_est);
  }
  catch (Exception e) {
    println("Error: "+e.getMessage());
  }
}

void keyPressed() {
  int v=10;
  if (key == CODED) {
    if (keyCode == RIGHT) {
      input=v;
    } else if (keyCode == LEFT) {
      input=-v;
    }
  }
}
void keyReleased() {
  if (key == CODED) {
    if (keyCode == RIGHT) {
      input=0;
    } else if (keyCode == LEFT) {
      input=0;
    }
  }
}

void disp(Mat M) {
  for (int i = 0; i < M.nrow; i++ ) {
    for (int j = 0; j < M.ncol; j++ ) {
      print(M.data[i][j]);
      print("\t");
    }
    print("\n");
  }
  print("\n");
}