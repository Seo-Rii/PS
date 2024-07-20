#include <ios>
#include <iostream>
#include <queue>

using namespace std;
int vi[105][105][105];
int xx[6] = {0, 0, 0, 0, 1, -1};
int yy[6] = {0, 0, 1, -1, 0, 0};
int zz[6] = {1, -1, 0, 0, 0, 0};

struct Data
{
    int x, y, z;
    int d;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<Data> q;
    int n, m, o, s = 0, ans = 0;
    cin >> m >> n >> o;
    for (int k = 0; k < o; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> vi[k][i][j];
                if (vi[k][i][j] == 1)
                    q.push({k, i, j, 0});
                if (!vi[k][i][j]) s++;
            }
    while (!q.empty())
    {
        auto [x, y, z, d] = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = x + xx[i];
            int ny = y + yy[i];
            int nz = z + zz[i];
            if (nx < 0 || nx >= o || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if (vi[nx][ny][nz]) continue;
            vi[nx][ny][nz] = 1;
            q.push({nx, ny, nz, d + 1});
            s--;
            ans = d + 1;
        }
    }
    if (s) cout << -1;
    else cout << ans;
}
