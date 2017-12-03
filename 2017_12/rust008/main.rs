use std::time::SystemTime;

fn prime1(n : i32) -> Vec<i32>{
    let mut prime = Vec::new();
    
    for i in 2..n{
        let mut flag = true;
        
        for p in prime.iter(){
            if i % p == 0 {
                flag = false;
            }
        }
        
        if flag {
            prime.push(i);
        }
    }
    
    prime
}

fn prime2(n : i32) -> Vec<i32>{
    fn f( xs : Vec<i32> ) -> Vec<i32>{
        if xs.len() == 0 {
            Vec::new()
        }else{
            let x = xs[0];
            //let filtered : Vec<i32> = xs.into_iter().filter(|n| n % x != 0).collect();
            let mut ret = f(xs.into_iter().filter(|n| n % x != 0).collect());
            ret.push(x);
            
            ret
        }
    };
    let mut ret = f( (2..n).collect() );
    ret.reverse();
    
    ret
}

fn display(xs : &Vec<i32>){
    for x in xs.iter(){
        println!("{}",x);
    }
}

fn main(){
    const N : i32 = 10000;
    
    let now = SystemTime::now();
    prime1(N.clone());
    let dur = now.elapsed().unwrap();
    println!("{}.{} s",dur.as_secs(),dur.subsec_nanos());
    
    
    // slow, and cause stack over flow if N is very large
    let now = SystemTime::now();
    prime2(N.clone());
    let dur = now.elapsed().unwrap();
    println!("{}.{} s",dur.as_secs(),dur.subsec_nanos());
    
   
}
