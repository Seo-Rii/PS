#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t, s = 0;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    cin >> t;
    for (auto i : v) if (i == t) s++;
    cout << s;
}
