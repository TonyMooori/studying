use std::io;

fn read_line() -> String{
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

// https://abc079.contest.atcoder.jp/tasks/abc079_a

fn main(){
    let line = read_line();
//    let split : Vec<&str> = line.trim().split(' ').collect();
    let split = line.trim().chars();
    let array : Vec<i32> = split.into_iter().map(|c| c.to_string().parse().unwrap()).collect();

    for i in 0..8{
        let mut sum = array[0];
        let mut output = String::new();

        output = format!("{}",array[0]);

        for j in 1..4{
            let mask = 1 << (j-1);
            let sign = if mask & i == 0 { 1 }else{ -1};
            let op = if sign == 1 {'+'}else{'-'};
            sum += sign * array[j];

            output = format!("{}{}{}",output,op,array[j]);
        }

        if sum == 7{
            println!("{}=7",output);
            break;
        }
    }

}
