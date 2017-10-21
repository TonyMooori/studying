boolean prevMousePressed = false;
int oldx, oldy;
int area;
int area_count;

void setup() {
  size(640, 480);
  refresh();
}

void refresh() {
  background(0);
  stroke(0, 255, 0);
  fill(0, 255, 0);
  ellipse(width/2, height/2, 10, 10);
  area = 0;
}

void draw() {
  //println(mx+  ","   + my);

  if (mousePressed) {
    int nx = mouseY-oldy;
    int ny = -(mouseX-oldx);

    if (prevMousePressed==false) {
      refresh();
    }

    area+=(mouseX*nx+mouseY*ny)/2;

    line(mouseX, mouseY, oldx, oldy);
  } else {
    if (prevMousePressed) {
      stroke(0);
      fill(0);
      ellipse(width/2, height/2, 20, 20);
      fillAll();
      stroke(0, 255, 0);
      fill(0, 255, 0);
    }
  }

  oldx = mouseX;
  oldy = mouseY;
  prevMousePressed=mousePressed;
}

void fillAll() {
  IntList xs, ys;
  int x, y;

  area_count = 0;
  xs = new IntList();
  ys = new IntList();

  xs.append(width/2);
  ys.append(height/2);

  while (xs.size()>0) {
    x = xs.get(0);
    y = ys.get(0);

    xs.remove(0);
    ys.remove(0);

    if ( x < 0 || x >= width || y < 0 || y >= height )
      continue;
    if ( get(x, y) != color(0, 0, 0) )
      continue;

    area_count++;

    set(x, y, color(0, 255, 0));
    xs.append(x+1);
    ys.append(y+0);

    xs.append(x-1);
    ys.append(y+0);

    xs.append(x+0);
    ys.append(y+1);

    xs.append(x+0);
    ys.append(y-1);
  }
  println("area = " + area);
  println("area_count = " + area_count);
}