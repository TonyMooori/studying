use std::io;

fn read_line() -> String{
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

// https://abc079.contest.atcoder.jp/tasks/abc079_a

fn main(){
    let line = read_line();
    let split : Vec<&str> = line.trim().split(' ').collect();
    let n : i32= split[0].parse().unwrap();
        
    if ((n/10)%111==0) || ((n%1000)%111==0){
        println!("Yes");
    }else{
        println!("No");
    }
}
