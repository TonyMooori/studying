fn main(){
    let suc = |x:i32| x+1;

    assert_eq!(2,suc(1));
    let suc2 = |x:i32|{
        suc(suc(x))
    };

    assert_eq!(2,suc2(0));
   
    let mut num = 2;
    let add_func = |x:i32| x+num;

    println!("{}",add_func(1));

    // num is borrowed by add_func
    //num = 10;
    //println!("{}",add_func(1));
    //

    let mut num = 5;
    {
        let mut add_num = |x:i32| num += x;
        add_num(5);
        // cannot print num because num is borrowed by add_num
        // println!("{}",num);
    }
    println!("{}",num);
    
    let mut num = 5;
    {
        let mut add_num = move|x:i32|{ num +=x; num};
        println!("{}",add_num(8));
        println!("{}",add_num(8));
    }
    println!("{}",num);

    let f = |x:i32|x+1;
    println!("{}",call_with_one1(&f));
    println!("{}",call_with_one(f));
}

fn call_with_one<F>(some_closure: F) -> i32
    where F:Fn(i32) -> i32{

    some_closure(1)
    }

fn call_with_one1<F>(some_closure: &F) -> i32
    where F:Fn(i32) -> i32{

    some_closure(1)
}



