use std::io;

fn read_line() -> String{
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

fn read_ints() -> Vec<i32>{
    let s = read_line();
    let split:Vec<&str> = s.trim().split(" ").collect();
    split.iter().map(|&x| x.to_string().parse().unwrap()).collect()
}

fn main(){
    //let array = read_ints();
    //let x = array[0];
    //let y = array[1];
    
    let line = read_line();
    let x = line.chars().nth(0).unwrap();
    let y = line.chars().nth(2).unwrap();

    let x = x as i32;
    let y = y as i32;

    match (x-y) {
        n if n < 0 => println!("<"),
        n if n > 0 => println!(">"),
        _ => println!("=")
    }
}

