use std::io;
use std::collections::HashMap;
use std::mem;

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
    let temp = read_ints();
    let n = temp[0];
    let m = temp[1];
    
    let mut from1 = HashMap::new();
    let mut fromn = HashMap::new();
    
    for _i in 0..m{
        let temp = read_ints();
        let mut a = temp[0];
        let mut b = temp[1];
        
        if a>b{
            mem::swap(&mut a,&mut b);
        }
        
        if a == 1{
            
            match fromn.get(&b){
                Some(_) => {println!("POSSIBLE");return;},
                None    => {from1.insert(b,true);}
            }
        }
        
        if b == n{
            match from1.get(&a){
                Some(_) => {println!("POSSIBLE");return;},
                None    => {fromn.insert(a,true);}
            }
        }
    }
    println!("IMPOSSIBLE");
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