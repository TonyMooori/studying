use std::io;
use std::collections::HashMap;
use std::mem;
use std::cmp;

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

fn f( n : i64 ) -> i64{
    if n == 0 {
        0
    }else{
        n % 10 + f(n/10)
    }
}

fn main(){
    let n = read_ints()[0];
    
    if n % f(n.clone()) == 0{
        println!("Yes");
    }else{
        println!("No");
    }
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