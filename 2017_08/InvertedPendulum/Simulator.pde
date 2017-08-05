// 制御対象のシミュレーション(非線形方程式)
RK4 sim = new RK4(
  new SimulationModel() {
  @Override
    public Mat dxdt(Mat x, float t, Mat u) {
    float r = x.data[0][0];// x[0] : r(位置)
    float v = x.data[1][0];// x[1] : v(速度)
    float theta = x.data[2][0];// x[2] : theta(角度)
    float omega = x.data[3][0];// x[3] : omega(角速度)

    Mat ret = new Mat(4, 1);
    Mat T = new Mat(2, 2);
    Mat temp= new Mat(2, 1);

    // 数式をそのまま落とし込んだだけ
    temp.data[0][0] = m*l*omega*omega*sin(theta)-B_dump*v+u.data[0][0];
    temp.data[1][0] = m*l*g*sin(theta)-C_dump*omega;

    T.data[0][0] = M+m;
    T.data[0][1] = m*l*cos(theta);

    T.data[1][0] = m*l*cos(theta);
    T.data[1][1] = J+m*l*l;

    try {
      temp = MatOp.mprod(MatOp.Inverse(T, false), temp);
    }
    catch(Exception e) {
      println("Exception: Cannot Calclate  T^{-1}");
    }

    ret.data[0][0]=v;
    ret.data[1][0]=temp.data[0][0];
    ret.data[2][0]=omega;
    ret.data[3][0]=temp.data[1][0];

    return ret;
  }
}
);