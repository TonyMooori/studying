static final float M = 5;
static final float m = 0.5;
static final float l = 3.0;
static final float J = m*l*l/3.0f;
static final float B_dump = 5.0;
static final float C_dump = 0.2;
static final float g = 9.8;
static final float detT = M*J+M*m*l*l+m*J;


Mat A_mat=new Mat(4, 4);
Mat B_mat=new Mat(4, 1);
Mat C_mat=new Mat(2, 4);

Mat K_mat=new Mat(1, 4);
Mat G_mat=new Mat(4, 2);

void set_params() {

  A_mat.data[0][0]=0;
  A_mat.data[0][1]=detT;
  A_mat.data[0][2]=0;
  A_mat.data[0][3]=0;

  A_mat.data[1][0]=0;
  A_mat.data[1][1]=-B_dump*(J+m*l*l);
  A_mat.data[1][2]=-m*m*l*l*g;
  A_mat.data[1][3]=C_dump*m*l;

  A_mat.data[2][0]=0;
  A_mat.data[2][1]=0;
  A_mat.data[2][2]=0;
  A_mat.data[2][3]=detT;

  A_mat.data[3][0]=0;
  A_mat.data[3][1]=B_dump*l*m;
  A_mat.data[3][2]=m*g*l*(M+m);
  A_mat.data[3][3]=-C_dump*(M+m);

  B_mat.data[0][0] = 0;
  B_mat.data[1][0] = J+m*l*l;
  B_mat.data[2][0] = 0;
  B_mat.data[3][0] = -m*l;

  // 1,0,0,0
  // 0,0,1,0
  C_mat.data[0][0] = 1;
  C_mat.data[1][2] = 1;

//  K_mat.data[0][0] =  214.96140116;
//  K_mat.data[0][1] = 301.8212799;
//  K_mat.data[0][2] = 2338.14612155;
//  K_mat.data[0][3] = 1467.66214847;

  G_mat.data[0][0] =9.7398596;
  G_mat.data[0][1]= 0.30567864;

  G_mat.data[1][0] =19.2229346;
  G_mat.data[1][1]= 0.30081657;

  G_mat.data[2][0] =0.30567864;
  G_mat.data[2][1]= 8.96145888;

  G_mat.data[3][0] = 6.87245941;
  G_mat.data[3][1]=15.09833317;



  G_mat.data[0][0] =  42.10823209;
  G_mat.data[0][1] = 8.72822737;

  G_mat.data[1][0] =420.62133365;
  G_mat.data[1][1] =165.24630059;

  G_mat.data[2][0] =8.72822737;
  G_mat.data[2][1] =28.59308639;

  G_mat.data[3][0] =153.7915084;
  G_mat.data[3][1] =102.53604218;
}