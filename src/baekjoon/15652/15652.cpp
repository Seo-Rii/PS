#include <ios>
#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int n, m;

void dfs(int l, int s)
{
    if (l == m + 1)
    {
        for (auto& i : v) cout << i << ' ';
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
    dfs(1, 1);
}
