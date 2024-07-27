#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[105][105], b[105][105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> b[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cout << a[i][j] + b[i][j] << ' ';
        cout << '\n';
    }
}
