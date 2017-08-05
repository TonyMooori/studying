// オブザーバ
RK4 observer = new RK4(
  new SimulationModel() {

  @Override
    public Mat dxdt(Mat z, float t, Mat u_y) {
    Mat ret=new Mat(4, 1);
    Mat u = new Mat(1, 1);
    Mat y = new Mat(2, 1);

    // パラメータとしてu,yがくっついたものが与えられる
    // 普通のu(1x1)とy(2x1)にする
    u.data[0][0] = u_y.data[0][0];

    y.data[0][0] = u_y.data[1][0];
    y.data[1][0] = u_y.data[2][0];

    try {
      ret = MatOp.add(ret, MatOp.mprod(A_mat, z));//Az
      ret = MatOp.add(ret, MatOp.mprod(B_mat, u));//Bu
      ret = MatOp.add(ret, MatOp.mprod(G_mat, MatOp.sub(y, MatOp.mprod(C_mat, z))));//G(y-Cz)
    }
    catch(Exception e) {
      println("Error: "+e.getMessage());
    }

    return ret;
  }
}
);