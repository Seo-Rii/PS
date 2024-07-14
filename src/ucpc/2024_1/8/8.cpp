#include <ios>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    long long ans = LONG_LONG_MAX, l = 0, r = 0, t;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        l = min(l, t);
        r = max(r, t);
    }
    l = -l;
    ans = min(ans, l * 2 + r * 2 + (l && r ? 2 * d : d));
    ans = min(ans, l * 4 + r * 4 + max(0ll, d - l * 2 - r * 2));
    ans = min(ans, l * 4 + r * 2 + d);
    ans = min(ans, l * 2 + r * 4 + d);
    cout << ans;
}
