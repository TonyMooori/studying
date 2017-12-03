use std::io;

fn read_line() -> String{
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

fn read_ints() -> Vec<i32>{
    let s = read_line();
    let split:Vec<&str> = s.trim().split(" ").collect();
    split.iter().map(|&x| x.to_string().parse().unwrap()).collect()
}

fn main(){
    //let array = read_ints();
    //let x = array[0];
    //let y = array[1];
    
    let xyz = read_ints();
    let x = xyz[0];
    let y = xyz[1];
    let z = xyz[2];
    
    let n = (x-z) / (y+z);
    println!("{}",n);
}

