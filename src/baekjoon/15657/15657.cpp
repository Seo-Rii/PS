#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v, mp;
int n, m;

void dfs(int l, int s)
{
    if (l == m + 1)
    {
        for (auto& i : v) cout << mp[i - 1] << ' ';
        cout << '\n';
        return;
    }
    for (int i = s; i <= n; i++)
    {
        v.push_back(i);
        dfs(l + 1, i);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    mp.resize(n);
    for (auto& i : mp) cin >> i;
    sort(mp.begin(), mp.end());
    dfs(1, 1);
}
