#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int s, n;

void dfs(int x, int m)
{
    if (x > n) return;
    if (x == n)
    {
        s++;
        return;
    }
    for (int i = m; i <= 3; i++)
    {
        dfs(x + i, 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        s = 0;
        cin >> n;
        dfs(0, 1);
        cout << s << endl;
    }
}
