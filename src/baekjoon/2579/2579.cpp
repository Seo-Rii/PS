#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, v[305][3] = {0};
    cin >> n;
    vector<int> l(n);
    for (auto& i : l) cin >> i;
    v[1][1] = l[0];
    for (int i = 2; i <= n; i++)
    {
        v[i][1] = max(v[i - 2][0], max(v[i - 2][1], v[i - 2][2])) + l[i - 1];
        v[i][2] = v[i - 1][1] + l[i - 1];
    }
    cout << max(v[n][0], max(v[n][1], v[n][2])) << endl;
}
