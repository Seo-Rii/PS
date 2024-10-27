#include <ios>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long v[300005], f[160005], b[160005];

void func(int tc)
{
    cout << "Case #" << tc << '\n';
    long long n, s, e, x;
    long long t1, t0;
    cin >> n >> s >> e;
    for (int i = 1; i <= n; i++) cin >> v[i];
    v[0] = v[n + 1] = 0;
    vector<long long> x1, x0;
    long long li = 0, fl = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (v[li] != v[i])
        {
            if (fl)
            {
                if (v[i]) x0.push_back(i - li);
                else x1.push_back(i - li);
            }
            else fl = 1;
            li = i;
        }
    }
    x = x1.size();
    if (x < 2)
    {
        cout << "0\n";
        return;
    }

    f[0] = 0;
    t1 = 0;
    t0 = 0;
    for (int i = 1; i < x; i++)
    {
        t1 += x1[i - 1];
        t0 += x0[i - 1];
        f[i] = min(t1 * e, t0 * s);
    }
    b[x - 1] = 0;
    t1 = 0;
    t0 = 0;
    for (int i = x - 1; i >= 1; i--)
    {
        t1 += x1[i];
        t0 += x0[i - 1];
        b[i - 1] = min(t1 * e, t0 * s);
    }

    long long ans = LONG_LONG_MAX;
    for (int i = 0; i < x; i++) ans = min(ans, f[i] + b[i]);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) func(i);
}
