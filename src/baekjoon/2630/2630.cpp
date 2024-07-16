#include <ios>
#include <iostream>
#include <queue>

using namespace std;
bool arr[130][130];
int b, w;

bool all(int x1, int y1, int x2, int y2)
{
    int v = arr[x1][y1];
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            if (v != arr[i][j]) return false;
    return true;
}

void dfs(int x1, int y1, int x2, int y2)
{
    if (all(x1, y1, x2, y2))
    {
        if (arr[x1][y1]) b++;
        else w++;
        return;
    }
    int mx = (x1 + x2) / 2;
    int my = (y1 + y2) / 2;
    dfs(x1, y1, mx, my);
    dfs(mx, y1, x2, my);
    dfs(x1, my, mx, y2);
    dfs(mx, my, x2, y2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, greater<>> pq;
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    dfs(0, 0, n, n);
    cout << w << endl << b << endl;
}
