fn main(){
    let n = 100;

    for i in 2..n{
        let mut flag = true;

        for j in 2..i-1{
            if i % j == 0{
                flag = false;
                break;
            }
        }

        if flag{
            println!("{}",i);
        }
    }
}
