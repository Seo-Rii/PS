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
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!v[i]) continue;
        if (i + 3 <= n) v[i + 3] = (!v[i + 3] || v[i + 3] > v[i] + 1) ? v[i] + 1 : v[i + 3];
        if (i + 5 <= n) v[i + 5] = (!v[i + 5] || v[i + 5] > v[i] + 1) ? v[i] + 1 : v[i + 5];
    }
    cout << (v[n] ? v[n] - 1 : -1) << '\n';
}
