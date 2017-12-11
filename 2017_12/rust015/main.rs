use std::io;
use std::collections::HashMap;
use std::collections::BinaryHeap;
use std::mem;
use std::cmp;

fn read_line() -> String{
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn read_ints() -> Vec<i64>{
    let s = read_line();
    let split:Vec<&str> = s.split(" ").collect();
    split.iter().map(|&x| x.to_string().parse().unwrap()).collect()
}


fn main(){
    let n = read_ints()[0];
    let mut xs = read_ints();
    let mut m  = 0;
    let mut out_x = Vec::new();
    let mut out_y = Vec::new();
    
    for i in 0..xs.len(){
        m = if xs[i].abs() < xs[m].abs(){m}else{i};
    }
    
    
    
    //println!("{},{}",m,xs[m]);
    
    if xs[m] > 0 {
        let mut idx = 0;
        
        loop{
            if idx == xs.len()-1{
                break;
            }
            
            if xs[idx] <= xs[idx+1]{
                idx += 1;
            }else{
                out_x.push(m+1);
                out_y.push(idx+1+1);
                
                xs[idx+1] += xs[m];
                m = if xs[idx+1].abs() < xs[m].abs(){m}else{idx+1};
            }
        }
    }else{
        let mut idx = xs.len()-1;
        
        loop{
            if idx == 0{
                break;
            }
            
            if xs[idx-1] <= xs[idx]{
                idx -= 1;
            }else{
                out_x.push(m+1);
                out_y.push(idx-1+1);
                
                xs[idx-1] += xs[m];
                m = if xs[idx-1].abs() < xs[m].abs(){m}else{idx-1};
            }
        }
    }
    
    println!("{}",out_x.len());
    
    for i in 0..out_x.len(){
        println!("{} {}",out_x[i],out_y[i]);
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

s.chars().nth(i as usize).unwrap();


// priority queue
// https://doc.rust-lang.org/std/collections/struct.BinaryHeap.html
use std::collections::BinaryHeap;
let mut heap = BinaryHeap::new();

heap.push(1);
heap.push(5);
heap.push(2);

assert_eq!(heap.pop(), Some(5));
assert_eq!(heap.pop(), Some(2));
assert_eq!(heap.pop(), Some(1));
assert_eq!(heap.pop(), None);


let mut vs = heap.into_vec();
vs.reverse();



*/