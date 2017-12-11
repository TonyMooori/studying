use std::fmt;
use std::ops::Add;

//implement: 実装する

struct Node;
struct Edge;
struct MyGraph;

trait Graph{
    type N;
    type E;
    
    fn has_edge(&self,&Self::N,&Self::N) -> bool;
    fn edges(&self,&Self::N) -> Vec<Self::E>;
}

impl Graph for MyGraph{
    type N = Node;
    type E = Edge;
    
    fn has_edge(&self,ns:&Node,ne:&Node) -> bool{
        true
    }
    
    fn edges(&self,n:&Node) -> Vec<Edge>{
        Vec::new()
    }
}

struct Point{
    x:i32,
    y:i32,
}

impl Add for Point{
    type Output = Point;
    
    fn add(self,other:Point) -> Point{
        Point{x:self.x + other.x,y:self.y + other.y}
    }
}

impl Add<i32> for Point{
    type Output = f64;
    
    fn add(self,rhs : i32) -> f64{
        0.5
    }
}


fn main(){
    let graph = MyGraph;
    let obj = Box::new(graph) as Box<Graph<E=Edge,N=Node>>;
    
    let p1 = Point{x:1,y:0};
    let p2 = Point{x:0,y:1};
    let p3 = p1+p2;
    
    println!("p3=({},{})",p3.x,p3.y);
    //println!("p1=({},{})",p1.x,p1.y);
    
    let p4 = Point{x:1,y:3};
    let val = p4 + 1i32;
    
    println!("val={}",val);
    
}