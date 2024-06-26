use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let v: Vec<i32> = s.split_whitespace().map(|i| i.trim().parse().unwrap()).collect();
    println!("{}", v[0] - v[1]);
}