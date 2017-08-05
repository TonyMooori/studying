public class RK4 {
  public RK4(SimulationModel model) {
    this.model = model;
  }

  // 状態変数をxとして，tからdtに変化した場合にxはどうなるかを計算するやつ
  Mat step(Mat x, float t, float dt, Mat u) throws Exception {
    Mat k1 = MatOp.sprod(dt, model.dxdt(x, t, u));
    Mat k2 = MatOp.sprod(dt, model.dxdt(MatOp.add(x, MatOp.sprod(0.5f, k1)), t+0.5f*dt, u));
    Mat k3 = MatOp.sprod(dt, model.dxdt(MatOp.add(x, MatOp.sprod(0.5f, k2)), t+0.5f*dt, u));
    Mat k4 = MatOp.sprod(dt, model.dxdt(MatOp.add(x, k3), t+dt, u));


    // dt * dx(t_n,x_n)
    // dt * (dx(t_(n+0.5),x_(n+0.5))
    // dt * (dx(t_(n+0.5),x_(n+0.5))
    // dt * (dx(t_(n+1),x_(n+1))
    //x = vv_add(x, sv_mul(1.0/6.0, dx_k1));
    //x = vv_add(x, sv_mul(2.0/6.0, dx_k2));
    //x = vv_add(x, sv_mul(2.0/6.0, dx_k3));
    //x = vv_add(x, sv_mul(1.0/6.0, dx_k4));

    // 足す
    k1 = MatOp.sprod(1.0f/6.0f, k1);
    k2 = MatOp.sprod(2.0f/6.0f, k2);
    k3 = MatOp.sprod(2.0f/6.0f, k3);
    k4 = MatOp.sprod(1.0f/6.0f, k4);

    Mat dx = MatOp.add(k1, k2, k3, k4);

    //dx = model.dxdt(x, t,u);
    //dx = MatOp.sprod(dx, dt);

    return MatOp.add(x, dx);
  }

  private SimulationModel model;
}