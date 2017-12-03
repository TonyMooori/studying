use std::io;
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

fn main(){
    let n = read_ints()[0];
    let xs = read_ints();
    let s : i64 = xs.iter().sum();
    
    let mut m = xs.iter().fold(0,|x,&y| cmp::max(x,y)) * n;
    let mut a : i64 = 0;
    
    for (idx,x) in xs.iter().enumerate(){
        if idx == xs.len() -1{
            break;
        }
        a += *x;
        m = cmp::min(m,(s - 2*a).abs());
    }
    println!("{}",m);
}

