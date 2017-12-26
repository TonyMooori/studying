// https://www.openprocessing.org/sketch/393873

void setup(){
  size(640,480);
  
  background(0);
  noStroke();
  translate(width/2,height/2);
  
  for(int i = 0 ; i < 360 ; i++ ){
    rotate(radians(5));
    drawJewels(width*random(0.05,0.1),0);
  }
}

void drawJewels(float x,float y){
  blendMode(MULTIPLY);
  drawPolygons(x,y,10,width*0.05);
  blendMode(ADD);
  drawPolygons(x,y,30,width*0.05);
}

void drawPolygons(float x,float y,int count,float r){
  pushMatrix();
  beginShape();
  translate(x,y);
  for(int i = 0 ; i < count ; i++ ){
    rotate(random(1));
    fill(random(5,50),random(50,255),random(5,50));
    vertex(random(-r,r),random(-r,r));
  }
  endShape();
  popMatrix();
}

void draw(){
  if(mousePressed){
  drawJewels(mouseX,mouseY);
  }
}