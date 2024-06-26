use std::io;

fn tc() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let v: Vec<i32> = s.split_whitespace().map(|i| i.trim().parse().unwrap()).collect();
    let [x1, y1, x2, y2] = v[..] else { panic!() };

    let mut cnt = 0;

    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    for _ in 0..s.trim().parse().unwrap() {
        let mut s = String::new();
        io::stdin().read_line(&mut s).unwrap();
        let v: Vec<i32> = s.split_whitespace().map(|i| i.trim().parse().unwrap()).collect();
        let [x, y, r] = v[..] else { panic!() };
        let i1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) < r * r;
        let i2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) < r * r;
        if i1 ^ i2 {
            cnt += 1
        }
    }
    println!("{}", cnt);
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    for _ in 0..s.trim().parse().unwrap() {
        tc()
    }
}