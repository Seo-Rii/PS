#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[1] = 0;
    for (int i = 2; i <= n; i++) v[i] = 2100000000;
    for (int i = 1; i <= n; i++)
    {
        if (i + 1 <= n) v[i + 1] = min(v[i + 1], v[i] + 1);
        if (i * 2 <= n) v[i * 2] = min(v[i * 2], v[i] + 1);
        if (i * 3 <= n) v[i * 3] = min(v[i * 3], v[i] + 1);
    }
    cout << v[n] << endl;
}
