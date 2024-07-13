#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;
bool f[600][600][3];
int n, m;
int xx[6] = {-1, 1, 0, 0, 0, 0};
int yy[6] = {0, 0, -1, 1, 0, 0};
int zz[6] = {0, 0, 0, 0, -1, 1};

bool inner(int i, int j, int k)
{
    return i >= 0 && i < n * 3 && j >= 0 && j < m * 3 && f[i][j][k] && k >= 0 && k < 3;
}

void dfs(int i, int j, int k)
{
    f[i][j][k] = false;
    for (int t = 0; t < 6; t++)
    {
        int ni = i + xx[t];
        int nj = j + yy[t];
        int nk = k + zz[t];
        if (inner(ni, nj, nk))
        {
            dfs(ni, nj, nk);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'O')
            {
                for (int k = 0; k < 3; k++)
                {
                    f[i * 3][j * 3][k] = true;
                    f[i * 3 + 2][j * 3][k] = true;
                    f[i * 3][j * 3 + 2][k] = true;
                    f[i * 3 + 2][j * 3 + 2][k] = true;
                }
            }
            else if (c == 'H')
            {
                for (int k = 0; k < 3; k++)
                {
                    f[i * 3][j * 3 + k][0] = true;
                    f[i * 3][j * 3 + k][2] = true;
                    f[i * 3 + 2][j * 3 + k][0] = true;
                    f[i * 3 + 2][j * 3 + k][2] = true;
                }
            }
            else if (c == 'I')
            {
                for (int k = 0; k < 3; k++)
                {
                    f[i * 3 + k][j * 3][0] = true;
                    f[i * 3 + k][j * 3][2] = true;
                    f[i * 3 + k][j * 3 + 2][0] = true;
                    f[i * 3 + k][j * 3 + 2][2] = true;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n * 3; i++)
    {
        for (int j = 0; j < m * 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (f[i][j][k])
                {
                    cnt++;
                    dfs(i, j, k);
                }
            }
        }
    }
    cout << cnt << endl;
}
