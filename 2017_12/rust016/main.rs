use std::io;
use std::collections::HashMap;
use std::collections::BinaryHeap;
use std::mem;
use std::cmp;

struct UnionFind<T>{
    par : HashMap<T,T>,
    rank: HashMap<T,i32>,
}

impl<T> UnionFind<T>
    where  T: Eq + std::hash::Hash  {
    
    fn new() -> UnionFind<T>{
        UnionFind{
            par : HashMap::new(),
            rank: HashMap::new(),
        }
    }
    
    fn find(&mut self,key: &T) -> &T {
        if self.par.contains_key(key) {
            let p = self.par.get(key).unwrap();
            
            if *p != *key{
                let root = self.find(p);
                self.par.insert(*key,*root);
            }
        }else{
            self.par.insert(*key,*key);
            self.rank.insert(*key,0);
        }
        
        self.par.get(key).unwrap()
    }
    
    fn unite(&mut self,k1 : &T,k2 : &T){
        let p1 = self.find(k1);
        let p2 = self.find(k2);
        
        if *p1 == *p2 {
            return;
        }
        
        if self.rank.get(p1).unwrap() < self.rank.get(p2).unwrap() {
            self.par.insert(*p1,*p2);
        }else{
            self.par.insert(*p2,*p1);
            
            if self.rank.get(p1).unwrap() == self.rank.get(p2).unwrap(){
                let r = self.rank.get(p1).unwrap();
                self.rank.insert(*p1,*r+1);
            }
        }
    }
    
    fn same(&mut self,k1:&T,k2:&T) -> bool{
        return self.find(k1) == self.find(k2);
    }
}

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