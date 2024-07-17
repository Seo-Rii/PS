#include <ios>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int number(string s)
{
    int n = 0;
    for (auto& c : s)
    {
        if (c < '0' || c > '9') return -1;
        n = n * 10 + c - '0';
    }
    return n;
}

void act(int n)
{
    if (n % 3 == 0 && n % 5 == 0) cout << "FizzBuzz" << endl;
    else if (n % 3 == 0) cout << "Fizz" << endl;
    else if (n % 5 == 0) cout << "Buzz" << endl;
    else cout << n << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    if (number(a) >= 0) act(number(a) + 3);
    else if (number(b) >= 0) act(number(b) + 2);
    else if (number(c) >= 0) act(number(c) + 1);
}
