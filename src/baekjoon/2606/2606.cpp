#include <ios>
#include <iostream>
#include <vector>

using namespace std;
vector<int> li[105];
bool vi[105];

void dfs(int x)
{
    if (vi[x]) return;
    vi[x] = true;
    for (auto& i : li[x]) dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        li[a].push_back(b);
        li[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++) if (vi[i]) ans++;
    cout << ans << endl;
}
