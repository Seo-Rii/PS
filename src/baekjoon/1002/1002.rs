use std::cmp::{max, min};
use std::io;

fn tc() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let v: Vec<i32> = s.split_whitespace().map(|i| i.trim().parse().unwrap()).collect();
    let [x1, y1, r1, x2, y2, r2] = v[..] else { panic!() };
    if x1 == x2 && y1 == y2 && r1 == r2 {
        println!("-1");
    } else {
        let d3 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        let (s1, s2) = ((r1 + r2) * (r1 + r2), (r1 - r2) * (r1 - r2));
        if d3 > s1 || s2 > d3 {
            println!("0");
        } else if d3 == s1 || s2 == d3 {
            println!("1");
        } else {
            println!("2");
        }
    }
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    for _ in 0..s.trim().parse::<usize>().unwrap() {
        tc()
    }
}