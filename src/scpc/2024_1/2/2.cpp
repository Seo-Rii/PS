#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tc(int cn)
{
    cout << "Case #" << cn + 1 << endl;

    int n;
    long long ans = 0;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i = 0; i < n / 4; ++i)
    {
        ans += (v[n - 1 - i] - v[i]) * 2;
    }
    cout << ans << endl;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) tc(i);
    return 0;
}
