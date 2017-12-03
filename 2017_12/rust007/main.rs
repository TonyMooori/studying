use std::io;
use std::collections::HashMap;
use std::mem;

fn read_line() -> String{
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

fn read_ints() -> Vec<i64>{
    let s = read_line();
    let split:Vec<&str> = s.trim().split(" ").collect();
    split.iter().map(|&x| x.to_string().parse().unwrap()).collect()
}

fn main(){
    let k = read_ints()[0];
    let d = k / 50;
    let m = k % 50;
    let m1 = m/3;
    let m2 = m/3;
    let m3 = m - m1 - m2;
    
    let bias = 49 + d - m;
    
    println!("50");
    
    print!("{} ",bias + m1 * 50);
    print!("{} ",bias + m2 * 50);
    print!("{} ",bias + m3 * 50);
    
    for i in 0..46{
        print!("{} ",bias);
    }
    println!("{} ",bias);
}







/*
DOCS


let mut h = HashMap::new();
let a = 5;
h.insert(a,true);
match h.get(&a){
    Some(v) => println!("{}",v),
    None    => println!("none"),
}


use std::mem;

let mut x = 5;
let mut y = 1;
mem::swap(&mut x,&mut y);


let v = vec![0;2]; // [0,0]







*/