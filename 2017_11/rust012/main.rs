#[derive(Debug)]
struct Point<T>{
    x:T,
    y:T,
}



fn main(){
    let p = Point{x:3,y:3};
    println!("{:?}",p);
}
