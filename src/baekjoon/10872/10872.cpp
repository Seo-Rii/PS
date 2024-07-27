#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, s = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) s *= i;
    cout << s;
}
