use std::io;
use std::collections::HashMap;
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
    let (n,nc) = (arr[0],arr[1]);
    let mut tables = Vec::new();
    let max_time = 100001 as usize;
    for i in 0..nc as usize{
        tables.push(vec![0;max_time*2]);
    }
    
    
    for i in 0..n as usize{
        let arr = read_ints();
        
        let s = (arr[0]-1) as usize;
        let t = (arr[1]-1) as usize;
        let c = (arr[2]-1) as usize;
        
        tables[c][(2*s  ) as usize]=1;
        tables[c][(2*t+1) as usize]=-1;
    }
    
    let mut ans = 0;
    let mut cnt = 0;
    
    
    for j in 0..nc as usize{
        for i in 0..max_time{
            if tables[j][2*i] == 1 && tables[j][2*i+1] == -1{
                tables[j][2*i+1] = 0;
                tables[j][2*i  ] = 0;
            }
        }
    }
    
    for i in 0..(2*max_time) as usize{
        for j in 0..nc as usize{
            cnt += tables[j][i];
        }
        ans = cmp::max(ans,cnt);
    }
    
    println!("{}",ans);
    
    /*
    let starts = Vec::new();
    let ends = Vec::new();
    let channels = Vec::new();
    
    for i in 0..n as usize{
        let arr = read_ints();
        starts.push(arr[0]);
        ends.push(arr[1]);
        channels.push(arr[2]-1);
    }*/
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