// Ref: jampack

class Mat {
  public Mat(float data[][]) {
    nrow = data.length;
    ncol = data[0].length;
    data = new float[nrow][ncol];

    for (int i = 0; i<nrow; i++)
      for (int j = 0; j < ncol; j++ )
        this.data[i][j] = data[i][j];
  }

  public Mat(int nrow, int ncol) {
    this.nrow = nrow;
    this.ncol = ncol;
    data = new float[nrow][ncol];
  }
  
  public Mat(Mat A){
    this.nrow = A.nrow;
    this.ncol = A.ncol;
    data = new float[nrow][ncol];
    for (int i = 0; i < A.nrow; i++ )
      for (int j = 0; j < A.ncol; j++ )
        data[i][j]=A.data[i][j];
  }

  public int nrow;
  public int ncol;
  public float[][] data;
}