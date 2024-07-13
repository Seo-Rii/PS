#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tc(int cn)
{
    cout << "Case #" << cn + 1 << endl;

    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<int> th;
    for (int i = 0; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
        if (v[a - 1].size() == 3) th.push_back(a - 1);
        if (v[b - 1].size() == 3) th.push_back(b - 1);
    }
    for (int i = 0; i < 3; ++i)
    {
        if (v[th[0]][i] == th[1])
        {
            v[th[0]].erase(v[th[0]].begin() + i);
            break;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        if (v[th[1]][i] == th[0])
        {
            v[th[1]].erase(v[th[1]].begin() + i);
            break;
        }
    }

    int prev = th[0], curr = v[th[0]][0];
    long long size = 1;
    while (curr != th[1])
    {
        if (v[curr][0] != prev)
        {
            prev = curr;
            curr = v[curr][0];
        }
        else
        {
            prev = curr;
            curr = v[curr][1];
        }
        size++;
    }
    long long rsize = n - size;
    long long ans = size * (size - 1) / 2 + rsize * (rsize - 1) / 2;
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
