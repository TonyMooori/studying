class Q_learning {
  private int nState;         // 状態数
  private int nAction;        // 行動の数
  private float[][] Q;        // Q値を格納する配列 
  private float alpha = 0.3;  // 学習率
  private float gamma = 0.7;  // 割引率
  private int oldState;       // ひとつ前の状態
  private int oldAction;      // ひとつ前の行動

  public Q_learning(int nState, int nAction) {
    // 各変数を代入し初期化
    this.nState = nState;
    this.nAction = nAction;
    this.Q = new float[nState][nAction];
    reset();
  }

  public void reset() {
    // はじめは-1を代入しておく
    this.oldState = -1;
    this.oldAction = -1;
  }

  // εグリーディ手法
  // 確率εでQ値とは無関係に行動を決定する
  public int getAction(int state, float eps) {
    int bestAction = 0;

    if ( eps >= random(1.0) ) {
      // 乱数選択
      bestAction = int(random(nAction));
    } else {
      // 最大のQ値を持つ行動を行う
      for (int i = 0; i < nAction; i++ )
        if ( Q[state][i] > Q[state][bestAction])
          bestAction = i;
    }

    return bestAction;
  }

  // 1段階処理を進める
  public void step(int state, int action, float reward) {
    
    if ( oldState != -1 ) {
      // ひとつ前の状態が存在するときQ値を更新
      update(oldState, oldAction, state, reward);
    }
    
    oldState = state;
    oldAction = action;
  }

  // Q値を更新
  private void update(int oldState, int oldAction, int nextState, float reward) {
    int nextAction = getAction(nextState, 0.0);

    Q[oldState][oldAction] = Q[oldState][oldAction] + 
      alpha * ( reward + gamma * Q[nextState][nextAction] - Q[oldState][oldAction]);
  }
}