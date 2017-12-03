use std::io;
use std::collections::HashMap;

fn read_line() -> String{
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

fn read_ints() -> Vec<i32> {
    let line = read_line();
    let split : Vec<&str> = line.trim().split(' ').collect();
    split.iter().map(|&x| x.to_string().parse().unwrap()).collect()
}

fn solve(xs : &Vec<i32>,yn_ans : &mut HashMap<i32,bool>,idx:usize,sum:i32){
    if idx < xs.len(){
        solve(xs,yn_ans,idx+1,sum+xs[idx]);
        solve(xs,yn_ans,idx+1,sum);
    }else{
        if yn_ans.contains_key(&sum){
            yn_ans.insert(sum,true);
        }
    }
}

fn main(){
    let n = read_ints()[0];
    let xs = read_ints();
    let q = read_ints()[0];
    let ms = read_ints();
    let mut yn_ans : HashMap<i32,bool>= HashMap::new();
    
    for m in ms.iter(){
        yn_ans.insert(*m,false);
    }
    
    solve(&xs,&mut yn_ans,0,0);
    
    for m in ms.iter(){
        match *yn_ans.get(m).unwrap(){
            true => println!("yes"),
            false => println!("no"),
        }
    }
}
