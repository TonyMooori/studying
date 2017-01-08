Board board;
boolean skip = false;
int n_loop;

void setup() {
  size(640, 480);

  // 環境を作成し初期化
  board = new Board(20, 20);
  board.reset();
  n_loop = 0;

  frameRate(60);
}

void draw() {
  int i = 0;

  do {
    // 1段階すすめる
    board.step();
    n_loop++;
    i++;
  } while ( skip && i < 1e3 );

  //skip = false;
  board.draw(100, 20, 20);
}

void keyPressed() {
  skip = !skip;
}