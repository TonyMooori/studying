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
    let n_store = read_ints()[0];
    let mut fss = Vec::new();
    let mut pss = Vec::new();
    let mut ans : i64 = -100000000000;
    
    for i in 0..n_store{
        fss.push(read_ints());
    }
    
    for i in 0..n_store{
        pss.push(read_ints());
    }
    
    for i in 1..1024{
        let mask = f(&mut i.clone());
        let mut benefit : i64 = 0;
        
        for j in 0..n_store as usize{
            let mut cnt = 0;
            
            for k in 0..10{
                if mask[k] == 1 && fss[j][k] == 1{
                    cnt += 1;
                }
            }
            
            benefit += pss[j][cnt];
        }
        
        ans = cmp::max(ans,benefit);
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