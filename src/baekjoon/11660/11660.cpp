#include <ios>
#include <iostream>

using namespace std;
int arr[1050][1050], sum[1050][1050];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x1, y1, x2, y2;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';
    }
}
