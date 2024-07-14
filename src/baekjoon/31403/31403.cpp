#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << endl;
    if (b >= 1000) cout << a * 10000 + b - c << endl;
    else if (b >= 100) cout << a * 1000 + b - c << endl;
    else if (b >= 10) cout << a * 100 + b - c << endl;
    else cout << a * 10 + b - c << endl;
}
