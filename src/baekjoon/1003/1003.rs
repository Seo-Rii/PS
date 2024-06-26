use std::io;

fn fibo(x: i32) -> usize {
    if x < 0 {
        return 0;
    }
    let (mut a, mut b) = (0, 1);
    for _ in 0..x {
        (a, b) = (b, a + b)
    }
    b
}

fn tc() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let n: i32 = s.trim().parse().unwrap();
    if n == 0 {
        println!("1 0");
    } else if n == 1 {
        println!("0 1");
    } else {
        println!("{} {}", fibo(n - 2), fibo(n - 1));
    }
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    for _ in 0..s.trim().parse().unwrap() {
        tc()
    }
}