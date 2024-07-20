#include <ios>
#include <iostream>
#include <string>

using namespace std;
bool v[550][550];
int n, m, k, h[550][550], s;
int xx[4] = {1, -1, 0, 0}, yy[4] = {0, 0, 1, -1};

void dfs(int x, int y)
{
    v[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + xx[i], ny = y + yy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !v[nx][ny] && abs(h[x][y] - h[nx][ny]) <= k) dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> h[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!v[i][j])
            {
                s++;
                dfs(i, j);
            }
        }
    cout << s << endl;
}
