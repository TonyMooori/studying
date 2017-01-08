class Board {
  private int W;  // 幅
  private int H;  // 高さ

  private Agent[] agents;                // Agentの配列
  private static final int N_AGENT = 3;  // Agentの数

  private Q_learning q1;  // agents[1]のQ値
  private Q_learning q2;  // agents[2]のQ値

  public Board(int W, int H) {
    this.W = W;
    this.H = H;

    // Agentの初期化
    agents = new Agent[N_AGENT];
    for (int i = 0; i < N_AGENT; i++ )
      agents[i] = new Agent(this);

    // Q値の初期化
    // 状態数は (1 + 25) * (1 + 25)
    // 行動は上下左右の4つ
    q1 = new Q_learning(26*26, 4);
    q2 = new Q_learning(26*26, 4);
    reset();
  }

  // 場をリセットする
  public void reset() {
    // 位置をランダムに配置
    for (int i = 0; i < N_AGENT; i++ )
      agents[i].randomPos();
    // Q値
    q1.reset();
    q2.reset();
  }

  // 1ステップ進める
  public void step() {
    // 状態と行動を取得
    int state1, action1;
    state1 = getState(agents[1], agents[2]);
    state1 = 26 * state1 + getState(agents[1], agents[0]);
    action1 = q1.getAction(state1, state1 == 675 ? 1.0 : 0.05);

    // 状態と行動を取得
    int state2, action2;
    state2 = getState(agents[2], agents[1]);
    state2 = 26 * state2 + getState(agents[2], agents[0]);
    action2 = q2.getAction(state2, state2 == 675 ? 1.0 : 0.05);

    // 行動
    agents[0].randomMove();
    agents[1].tryMove(action1);
    agents[2].tryMove(action2);

    // 囲まれているかどうかを確認
    boolean flag = agents[0].isSurrounded();

    if ( flag ) {
      // 終了してたら報酬を与えてリセット
      q1.step( state1, action1, 10);
      q2.step( state2, action2, 10);
      reset();
      println("catched " + n_loop);
    } else {
      // 終了してなければ負の報酬を与えて行動
      q1.step( state1, action1, -1);
      q2.step( state2, action2, -1);
    }
  }

  private int getState(Agent left, Agent right) {
    int dx = left.getX() - right.getX()+2;
    int dy = left.getY() - right.getY()+2;
    if ( dx < 0 || 5 <= dx )return 25;
    if ( dy < 0 || 5 <= dy )return 25;
    return dx*5+dy;
  }

  public int getW() {
    return W;
  }

  public int getH() {
    return H;
  }

  // 指定した座標に何もないか確認する関数
  public boolean isEmpty(int x, int y) {
    for (int i = 0; i < N_AGENT; i++ )
      if ( x == agents[i].getX() && y == agents[i].getY() )
        return false;
    return true;
  }

  public void draw(int x, int y, int boxSize) {
    pushMatrix();
    translate(x, y);
    
    // 場を描く
    fill(0, 255, 0);
    stroke(0, 255, 0);
    for (int i = 0; i < W; i++ ) 
      for (int j = 0; j < H; j++ ) 
        rect(  i * boxSize, j*boxSize, boxSize, boxSize);

    // エージェントを描く
    fill(0, 255, 255);
    stroke(0, 255, 255);
    agents[1].draw(boxSize);
    agents[2].draw(boxSize);
    fill(255, 255, 0);
    stroke(255, 255, 0);
    agents[0].draw(boxSize);
    
    popMatrix();
  }
}