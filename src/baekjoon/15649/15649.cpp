#include <ios>
#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int n, m;

void dfs(int l)
{
    if (l == m + 1)
    {
        for (auto& i : v) cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        bool fl = true;
        for (auto& j : v) if (j == i) fl = false;
        if (fl)
        {
            v.push_back(i);
            dfs(l + 1);
            v.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    dfs(1);
}
