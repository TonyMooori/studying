use std::io;
use std::cmp;
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

#[test]
fn check(){
    assert_eq!(2,1+1);
}

#[inline(always)]
fn suc(x:i32)->i32{
    x+1
}

type Name = String;
type i32_t = i32;

fn main(){
    let x:Name = "hello".to_string();
    let n:i32_t = 1;
    let m:i32   = 2;

    // comparison between i32_t and i32
    // but this compiles without error 
    // because i32_t is an alias of i32
    println!("{}",n==m);
    
    unsafe{
        let a : [u8;4] = [0,0,1,0];
        let b = mem::transmute::<[u8;4],u32>(a);
        let c : u32 = mem::transmute(a);
        println!("{}",b);
        println!("{}",c);
    }
}

