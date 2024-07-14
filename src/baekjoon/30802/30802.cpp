#include <ios>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s, m, l, xl, xxl, xxxl, t, p;
    cin >> n >> s >> m >> l >> xl >> xxl >> xxxl >> t >> p;
    cout << (s + t - 1) / t + (m + t - 1) / t + (l + t - 1) / t + (xl + t - 1) / t + (xxl + t - 1) / t + (xxxl + t - 1)
        / t << endl;
    cout << n / p << ' ' << n % p << endl;
}
