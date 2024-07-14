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
    if (!n)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    int k = round(n * 0.15), s = 0;
    for (int i = k; i < n - k; i++) s += v[i];
    cout << round(s * 1.0 / (n - 2 * k)) << endl;
    return 0;
}
