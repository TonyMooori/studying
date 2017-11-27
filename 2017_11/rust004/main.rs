struct Foo<'a>{
    x:&'a i32,
}

impl<'a> Foo<'a>{
    fn x(&self) -> &'a i32{self.x}
}

fn skip_prefix<'a,'b>(line:&'a str,prefix:&'b str) -> &'a str {
    line 
}

fn main(){
    let line = "lang:en=Hello World";
    let lang = "en";

    let v;
    {
        let p = format!("lang:{}=",lang);
        v = skip_prefix(line,p.as_str());
    }

    println!("{}",v);

    let y = &5;
    let f = Foo{x:y};

    println!("x is  {}",f.x());
}
