float input;
float old_time;

Mat x_now=new Mat(4, 1);
Mat x_est=new Mat(4, 1);

void setup() {
  set_params();

  old_time = millis()/1000.0f;
  size(640, 540);

  x_est.data[0][0] = 0.001;
  x_est.data[2][0] = 0.001;
  x_est.data[1][0] = 0.001;
  x_est.data[3][0] = 0.001;
}

void draw() {
  background(0);
  translate(width/2, height/2);
  float t = millis()/1000.0f;
  float dt = t - old_time;
  float x;
  float theta;
  old_time =t;

  Mat u=new Mat(1, 1);
  Mat u_y=new Mat(3, 1);

  //  try {
  //    u = MatOp.mprod(K_mat, x_est);
  //  }
  //  catch(Exception e) {
  //    println("Error: "+e.getMessage());
  //  }

  //u.data[0][0]+=+200*x_now.data[2][0]+input;

  u_y.data[0][0] = u.data[0][0];
  u_y.data[1][0] = x_now.data[0][0];
  u_y.data[2][0] = x_now.data[2][0];

  try {
    x_now = sim.step(x_now, t, dt, u );


    x=x_now.data[0][0];
    theta=x_now.data[2][0];

    stroke(255);
    strokeWeight(5);
    fill(0);
    rect(x*100-40, -25, 80, 50);
    line(x*100, 0, x*100+100*sin(theta), -100*cos(theta));


    x_est = observer.step(x_est, t, dt, u_y);

    disp(x_est);

    disp(A);

    x = x_est.data[0][0];
    theta = x_est.data[2][0];

    stroke(0, 255, 0);
    strokeWeight(3);
    fill(0);
    rect(x*100-40, -25, 80, 50);
    line(x*100, 0, x*100+100*sin(theta), -100*cos(theta));
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