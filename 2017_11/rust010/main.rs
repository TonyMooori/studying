struct Circle{
    x:f64,
    y:f64,
    radius:f64
}

impl Circle{
    fn area(&self) -> f64{
        std::f64::consts::PI * (self.radius *self.radius)
    }

    fn grow(&self,increment : f64)->Circle {
        Circle{x:self.x,y:self.y,radius:self.radius * increment}
    }

    fn new(area:f64) -> Circle{
        Circle{x:0.0,y:0.0,radius:(area/std::f64::consts::PI).sqrt()}
    }
}

struct CircleBuilder{
    x : f64,
    y : f64,
    radius : f64
}

impl CircleBuilder{
    fn new() -> CircleBuilder{
        CircleBuilder{x:0.0,y:0.0,radius:0.0}
    }

    fn x(&mut self,val : f64) -> &mut CircleBuilder{
        self.x = val;
        self
    }

    fn y(&mut self,val : f64)-> &mut CircleBuilder{
        self.y = val;
        self
    }

    fn radius(&mut self,val:f64) -> &mut CircleBuilder{
        self.radius = val;
        self
    }

    fn finalize(&mut self) -> Circle{
        Circle{x:self.x,y:self.y,radius:self.radius}
    }
}

fn main(){
    let c = Circle{x:0.0,y:0.0,radius:2.0};
    println!("{}",c.area());
    println!("{}",c.grow(2.0).area());

    let c = Circle::new(10.0);
    println!("{}",c.area());

    let c = CircleBuilder::new()
                .x(1.0)
                .y(2.0)
                .finalize();
    println!("{}",c.x);

}


