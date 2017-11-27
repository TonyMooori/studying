enum Message{
    Quit,
    ChangeColor(i32,i32,i32),
    Move{x:i32,y:i32},
    Write(String),
}

fn foo(x:String)->Message{
    Message::Write(x)
}

fn foo2(x:&str)->Message{
    Message::Write(x.to_string())
}

fn main(){
    let message : Message = Message::Move{x:3,y:4};
    let sample = foo("sample".to_string());
    let sample2 = foo2("sample2");


    match message {
        Message::Quit => println!("quit"),
        Message::ChangeColor(x,..)=> println!("change color,x={}",x),
        Message::Move{x,y:neko} => println!("Move {}",neko),
        Message::Write(s) => println!("{}",s),    
    }

    for i in 1..30{
        let m3 = i % 3;
        let m5 = i % 5;

        match (m3,m5) {
            (0,0) => println!("Fizz Buzz"),
            (0,_) => println!("Fizz"),
            (_,0) => println!("Buzz"),
            (_,_) => println!("{}",i),
        }
    }
    let n = 100;
    match n {
        1 | 2 => println!("one or two"),
        a @ 3...6  => println!("3,4,5,6,the value is {}",a), // note:including 6
        a @ 9...10 | a @ 100...101 => println!("great!{}",a),
        _     => println!("anything")
    }

    match 'c'{
        'a'...'z' => println!("small"),
        'A'...'Z' => println!("big"),
        _ => (),

    }
}

