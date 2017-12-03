use std::io;

fn read_line() -> String{
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

fn read_ints() -> Vec<i32> {
    let line = read_line();
    let split : Vec<&str> = line.trim().split(' ').collect();
    split.into_iter().map(|s| s.to_string().parse().unwrap()).collect()
}


fn main(){
    // let array : Vec<i32> = split.into_iter().map(|c| c.to_string().parse().unwrap()).collect();
    let array = read_ints();
    let (h,w)  = (array[0] as usize,array[1] as usize);
    let mut table = Vec::new();
    let mut map = Vec::new();
    
    for i in 0..10{
        table.push(read_ints());
    }
    
    for i in 0..h{
        map.push(read_ints());
    }
    
    let mut flag = true;
    
    while flag{
        
        flag = false;
        //println!("a");
        for i in 0..10{
            for j in 0..10{
                for k in 0..10{
                    if table[i][k] > table[i][j]+table[j][k]{
                        flag = true;
                        table[i][k] = table[i][j]+table[j][k];
                    }
                }
            }
        }
    }
    
    let mut ans = 0;
    
    for i in 0..h{
        for j in 0..w{
            if map[i][j] < 0{
                continue;
            }
            
            ans += table[map[i][j] as usize ][1];
        }
    }
    
    println!("{}",ans);
    //println!("{}",table[8][1]);
 
}