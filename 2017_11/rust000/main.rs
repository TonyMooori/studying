fn main(){
    let mut x = 5;
    let mut done = false;

    while !done{
        x+=x-3;
        println!("{}",x);
        if x % 5 == 0{
            done = true;
        }
    }
   
    for i in 0..10{
        println!("{}",i);
    }

    for (index,value) in (5..10).enumerate(){
        println!("(5..10)[{}]=[{}]",index,value);
    }

    let lines = "hello\nworld".lines();

    for (linenumber,line) in lines.enumerate(){
        println!("line {}: {}",linenumber,line);
    }

    'outer: for i in 1..10{
        'inner: for j in 1..10{
            if i<j{
                break 'inner;
            }

            print!("{}\t",i*j);
        }
        println!("");
    }

}

