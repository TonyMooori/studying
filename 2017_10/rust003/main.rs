fn main(){
    let x = 32;
    let y:i32;
    let z:i32=3;

    y=5;
    // y=2; // 最初の一回はokだけどその後に代入はできない

    let z = 33;// これは代入できるというか前のzは別物扱い(shadowing)
    
    println!("value = {} , {} , {} ",x,y,z);
    print_sum(x,y);


}

fn print_sum(x:i32,y:i32){ // 引数には明示的に型を示さなければならない
    println!("sum is : {}",x+y);
}


