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
    let arr = read_ints();
    let (n,k) = (arr[0] as i32,arr[1] as i32);
    let mut cnt : Vec<i32> = vec![0;200005];
    let mut heap = BinaryHeap::new();
    let mut n_color = 0 as i32;
    
    let arr = read_ints();
    for idx in arr.iter(){
        cnt[*idx as usize] += 1;
    }
    
    for i in 0..200005{
        if cnt[i]>0 {
            heap.push(cnt[i]);
            n_color+=1;
        }
    }
    
    let mut vs : Vec<i32>= heap.into_vec();
    vs.reverse();
    
    let mut ans = 0;
    
    for v in vs.iter(){
        if n_color > k{
            ans += *v;
            n_color -= 1;
        }
    }
    println!("{}",ans);
}

/*
struct Uf{
    n_size: usize,
    par   : Vec<i32>,
    rank  : Vec<i32>,
}

impl Uf{
    fn new(n_size:usize) -> Uf{
        Circle{
            n_size:n_size,
            par  :(0..n_size).collect(),
            rank :vec![0;n_size]
        }
    }
    
    fn find(&self, x: i64)->i64{
        let h = self.hash(x);
        
        if( par[h] == x ){
            x
        }else{
            par[h] = self.find(x);
            
        }
    }
}

*/



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





*/