#include <ios>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n, a, b, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    v.resize(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int x = 0; x < a; x++)
    {
        for (int sl = 0; sl <= n; sl++)
        {
            int t = 0, ta = a, i = 0, s = 0;
            for (i = 0; i < n; i++)
            {
                if (sl == i)
                {
                    t += b * x;
                    ta -= x;
                }
                t += ta;
                while (t > v[i] && i < n) i++;
                if (i == n) break;
                s++;
            }
            ans = max(ans, s);
        }
    }
    cout << ans << endl;
}
