#include <ios>
#include <iostream>
#include <queue>

using namespace std;
int vi[1005][1005];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};

struct Data
{
    int x, y;
    int d;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<Data> q;
    int n, m, s = 0, ans = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> vi[i][j];
            if (vi[i][j] == 1)
                q.push({i, j, 0});
            if (!vi[i][j]) s++;
        }
    while (!q.empty())
    {
        auto [x, y, d] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vi[nx][ny]) continue;
            vi[nx][ny] = 1;
            q.push({nx, ny, d + 1});
            s--;
            ans = d + 1;
        }
    }
    if (s) cout << -1;
    else cout << ans;
}
