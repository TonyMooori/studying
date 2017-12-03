use std::process;

fn is_inner(nx:i32,ny:i32) -> bool{
    0 <= nx && nx < 8 && 0 <= ny && ny < 8 
}

fn check_line( table : &Vec<bool>, x: i32,y :i32) -> bool{

    let vx = vec![1,1,0,-1,-1,-1, 0,1];
    let vy = vec![0,1,1,1, 0,-1,-1,-1];
    
    for i in 0..8{
        let mut nx = x;
        let mut ny = y;
        let mut count = 0;
        
        while is_inner(nx,ny){
            let idx = (nx*8+ny) as usize;
            if table[idx]{
                count += 1;
            }
            nx += vx[i];
            ny += vy[i];
        }
        
        if count != 1{
            return false
        }
    }
    
    return true;
}

fn check( table : &Vec<bool>) -> bool{
    
    for i in 0..8{
        for j in 0..8{
            if table[(i*8+j) as usize]{
                let flag = check_line(table,i,j);
                if flag == false{
                    return false;
                }
            }
        }
    }
    
    return true;
}

fn display(table:&Vec<bool>){
    for i in 0..8{
        for j in 0..8{
            let idx = (i*8+j) as usize;
            if table[idx] {
                print!("Q");
            }else{
                print!("*");
            }
        }
        println!("");
    }
    println!("");
}

fn n_qeen(table : &mut Vec<bool>, n : i32){
    if n == 8{
        display(table);
        process::exit(0);
    }else{
        for i in 0..8{
            let idx = (i*8+n) as usize;
            table[idx]=true;
            if check(table){
                n_qeen(table,n+1);
            }
            table[idx]=false;
        }
    }
}


fn main(){
    let mut table = Vec::new();
    
    for i in 0..64{
        table.push(false);
    }
    
    n_qeen(&mut table,0);
}
