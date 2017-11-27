struct Point{
    x:i32,
    y:i32,
}

#[derive(Debug)]
struct PersonA<'a>{
    name : &'a str,
    age : u8
}
/*
struct PersonB{
    name:&str,
    age:u8
}
*/
fn main(){
    let origin = Point{x:0,y:0};
    println!("The origin is at ({},{})",origin.x,origin.y);

    let name = "Peter";
    let age = 25;
    let peter = PersonA{name,age};

//    let nameb = "sample";
//    let ageb = 55;
//    let smpl = PersonB{nameb,ageb};

    println!("{:?}",peter);


    // age:5 とすると ageは5 になる
    // その後に .. (構造体の変数名) とすればそれ以外のパラメータをコピーする
    let tom = PersonA{age:5,..peter};
    println!("{:?}",tom);
}

