#include <ios>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, c = 0, t, s = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i + 1;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        int idx = find(v.begin(), v.end(), t) - v.begin();
        s += min((c - idx + n) % n, (idx - c + n) % n);
        v.erase(v.begin() + idx);
        n--;
        c = idx;
    }
    cout << s << endl;
}
