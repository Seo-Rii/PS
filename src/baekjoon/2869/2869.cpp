#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, v;
    cin >> a >> b >> v;
    cout << (v - a + a - b - 1) / (a - b) + 1 << endl;
}
