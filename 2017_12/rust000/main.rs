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

fn f(n : &mut i64)-> Vec<i64>{
    let mut ret = Vec::new();
    
    for i in 0..10{
        ret.push(*n%2);
        *n /= 2;
    }
    
    ret
}

fn main(){
    let arr = read_ints();
    let (n,x) = (arr[0],arr[1]);
    let s : String = read_line().trim().to_string();
    let mut ans = 0;
    
    for i in 0..n{
        let c = s.chars().nth(i as usize).unwrap();
        let t = read_ints()[0];
        if c == '0'{
            ans += t;
        }else{
            ans += cmp::min(t,x);
        }
    }
    println!("{}",ans);
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