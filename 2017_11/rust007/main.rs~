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

    let mut vec = Vec::new();
    vec.push(2 as i64);
    vec.push(1);

    for i in 0..n-1{
        let len = vec.len();
        let v = vec[len-1] + vec[len-2];
        vec.push(v);
    }

    println!("{}",vec[n as usize]);

}
