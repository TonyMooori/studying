import java.lang.Exception;

// mprod   : 行列の掛け算
// sprod   : 行列xスカラーの掛け算
// hprod   : アダマール積
// add     : 行列の要素ごとの足し算
// sub     : 行列の要素ごとの引き算
// LUdecomp: 行列をLU分解するやつ．正則でもできない場合がある
// LUSolve : 連立方程式とくやつ
// Inverse : 逆行列

public class MatOp {
  public static Mat mprod(Mat A, Mat B) throws Exception {
    Mat ret = new Mat(A.nrow, B.ncol);

    if ( A.ncol != B.nrow )
      throw new Exception("mismatch of matrix size");

    for (int i=0; i<A.nrow; i++) {
      for (int k=0; k<A.ncol; k++) {
        for (int j=0; j<B.ncol; j++) { 
          ret.data[i][j] += A.data[i][k]*B.data[k][j];
        }
      }
    }
    return ret;
  }

  public static Mat sprod(float s, Mat A) {
    Mat ret = new Mat(A);
    for (int i = 0; i < A.nrow; i++ )
      for (int j = 0; j < A.ncol; j++ )
        ret.data[i][j]*=s;

    return ret;
  }

  // Hadamard product
  public static Mat hprod(Mat A, Mat B)throws Exception {
    Mat ret = new Mat(A);

    if ( A.ncol != B.ncol || A.nrow != B.nrow)
      throw new Exception("mismatch of matrix size");

    for (int i = 0; i < A.nrow; i++ )
      for (int j = 0; j < A.ncol; j++ )
        ret.data[i][j]*=B.data[i][j];

    return ret;
  }

  public static Mat add(Mat A, Mat B)throws Exception {
    Mat ret = new Mat(A);

    if ( A.ncol != B.ncol || A.nrow != B.nrow)
      throw new Exception("mismatch of matrix size");

    for (int i = 0; i < A.nrow; i++ )
      for (int j = 0; j < A.ncol; j++ )
        ret.data[i][j]+=B. data[i][j];

    return ret;
  }

  public static Mat sub(Mat A, Mat B)throws Exception {
    Mat ret = new Mat(A);

    if ( A.ncol != B.ncol || A.nrow != B.nrow)
      throw new Exception("mismatch of matrix size");

    for (int i = 0; i < A.nrow; i++ )
      for (int j = 0; j < A.ncol; j++ )
        ret.data[i][j]-=B. data[i][j];

    return ret;
  }

  public static Mat LUdecomp(Mat A) throws Exception {
    Mat lu = new Mat(A.nrow, A.ncol);
    int n = A.ncol;

    if ( A.nrow != n )
      throw new Exception("mismatch of matrix size");

    for (int j=0; j<n; j++) {
      for (int i = 0; i <= j; i++ ) {
        lu.data[i][j]=A.data[i][j];

        for (int k=0; k<i; k++)
          lu.data[i][j] -= lu.data[i][k]*lu.data[k][j];
      }

      if ( Math.abs(lu.data[j][j])<1e-4) {
        throw new Exception("cannot lu decomposition");
      }

      for (int i = j+1; i < n; i++ ) {
        lu.data[i][j] = A.data[i][j];

        for (int k = 0; k < j; k++)
          lu.data[i][j] -= lu.data[i][k]*lu.data[k][j];


        lu.data[i][j] /= lu.data[j][j];
      }
    }

    return lu;
  }

  // is_decomp: lu分解済みだったらtrue,そうじゃなかったらfalse
  public static Mat LUSolve(Mat A, Mat b, boolean is_decomp) throws Exception {
    int n = A.ncol;
    Mat x =new Mat(b.nrow, b.ncol);
    Mat y = new Mat(b.nrow, b.ncol);

    // L(Ux)=b
    // Ly = b
    // Ux = y

    if ( n != b.nrow )
      throw new Exception("mismatch of matrix size");

    if (is_decomp==false)A=LUdecomp(A);

    // y
    for (int bcol = 0; bcol < b.ncol; bcol++ ) {
      for (int i = 0; i < n; i++ ) {
        y.data[i][bcol] = b.data[i][bcol];

        for (int j = 0; j < i; j++ ) {
          y.data[i][bcol] -= A.data[i][j]*y.data[j][bcol];
        }
      }
    }

    // x
    for (int bcol = 0; bcol < b.ncol; bcol++ ) {
      for (int i = n-1; i >= 0; i-- ) {
        x.data[i][bcol]=y.data[i][bcol];

        for (int j = i+1; j<n; j++) {
          x.data[i][bcol] -= A.data[i][j]*x.data[j][bcol];
        }

        x.data[i][bcol] /= A.data[i][i];
      }
    }


    return x;
  }

  public static Mat Inverse(Mat A, boolean is_decomp) throws Exception {
    Mat b = new Mat(A.nrow, A.ncol);

    if ( A.nrow != A.ncol )
      throw new Exception("mismatch of matrix size");

    for (int i = 0; i< A.nrow; i++ )
      b.data[i][i]=1;
    return LUSolve(A, b, is_decomp);
  }

  public static Mat mprod(Mat A, Mat B, Mat C) throws Exception {
    return mprod(mprod(A, B), C);
  }

  public static Mat mprod(Mat A, Mat B, Mat C, Mat D) throws Exception {
    return mprod(mprod(A, B), mprod(C, D));
  }

  public static Mat sprod(Mat A, float s) {
    return sprod(s, A);
  }

  public static Mat hprod(Mat A, Mat B, Mat C) throws Exception {
    return hprod(A, hprod(B, C));
  }

  public static Mat add(Mat A, Mat B, Mat C) throws Exception {
    return add(A, add(B, C));
  }

  public static Mat add(Mat A, Mat B, Mat C, Mat D) throws Exception {
    return add(add(D, A), add(B, C));
  }
}