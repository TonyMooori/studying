class Agent {
  private int x, y, W, H;
  private Board board;
  int[] dx = {-1, 0, 0, 1};
  int[] dy = {0, -1, 1, 0};

  public Agent(Board board) {
    x = y = 0;
    this.board = board;
    this.W = board.getW();
    this.H = board.getH();
  }

  public void setPos(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public void randomPos() {
    int tempX, tempY;
    do {
      tempX = int(random(W));
      tempY = int(random(H));
    } while ( tryMove(tempX, tempY) == false );

    // 囲まれた状態スタートだとrandomMoveで無限ループに入るため
    if ( isSurrounded() )
      randomPos();
  }

  public void randomMove() {
    int tempX, tempY;
    do {
      int index = int(random(4));
      tempX = constrain(x + dx[index], 0, W-1);
      tempY = constrain(y + dy[index], 0, H-1);
    } while ( tryMove(tempX, tempY) == false );
  }

  public boolean tryMove(int action) {
    action = constrain(action, 0, 3);
    return tryMove(x+dx[action], y+dy[action]);
  }

  public boolean tryMove(int nextX, int nextY) {
    if ( nextX < 0 || W <= nextX || nextY < 0 || H <= nextY )
      return false;

    if ( board.isEmpty(nextX, nextY) ) {
      x = nextX;
      y = nextY;
      return true;
    } else {
      return false;
    }
  }

  public boolean isSurrounded() {
    int count = 0;
    for (int i = 0; i < 4; i++ )
      if ( board.isEmpty( x + dx[i], y+dy[i] ) == false )
        count++;
    return count >= 2;
  }

  public int getX() {
    return x;
  }

  public int getY() {
    return y;
  }

  public void draw(int boxSize) {
    rect(x*boxSize, y*boxSize, boxSize, boxSize);
  }
}