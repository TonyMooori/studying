
RK4 observer = new RK4(
  new SimulationModel() {

  @Override
    public Mat dxdt(Mat z, float t, Mat u_y) {
    Mat ret=new Mat(4, 1);
    Mat u = new Mat(1, 1);
    Mat y = new Mat(2, 1);

    u.data[0][0] = u_y.data[0][0];

    y.data[0][0] = u_y.data[1][0];
    y.data[1][0] = u_y.data[2][0];

    disp(y);

    try {
      ret = MatOp.add(ret, MatOp.mprod(A_mat, z));
      ret = MatOp.add(ret, MatOp.mprod(B_mat, u));
      ret = MatOp.add(ret, MatOp.mprod(G_mat, MatOp.sub(y, MatOp.mprod(C_mat, z))));
    }
    catch(Exception e) {
      println("Error: "+e.getMessage());
    }

    ret=MatOp.sprod(ret, 1/detT);

    return ret;
  }
}
);