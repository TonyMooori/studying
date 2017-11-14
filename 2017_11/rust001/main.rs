fn main(){
    let v:Vec<i32>  = vec![1,2,3,4,5];
    let v1 = vec![0;10];// a vector of ten zeros

    for x in v{
        println!("{}",x);
    }

    println!("{}",v1[2]);

    match v1.get(99){
        Some(x) => println!("the item is {}",x),
        None => println!("Sorry! there is no item!")
    }
 
    for x in &v1{
        println!("v1 = {}",x);
    }

    for x in &v1{
        println!("v1 = {}",x);
    }
   
}

