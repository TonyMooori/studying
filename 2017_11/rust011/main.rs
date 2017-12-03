fn main(){
    let s1 = "Hello World";
    let s2 = "Hello
    World";
    let s3 = "Hello \
    World";

    println!("{}",s1);
    println!("{}",s2);
    println!("{}",s3);

    let hachiko ="忠犬ハチ公";

    for b in hachiko.as_bytes(){
        print!("{}, ",b);
    }
    
    println!("");

    for c in hachiko.chars(){
        print!("{}, ",c)
    }
    
    println!("");

    println!("the first character of {} is {:?}",hachiko,hachiko.chars().nth(0));
    println!("{}",&hachiko[0..3]);

    let hello = "Hello".to_string();
    let world = "World";
    let hw = hello + world;
    println!("{}",hw);
}
