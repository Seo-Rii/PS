#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, s = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    reverse(v.begin(), v.end());
    for (auto& i : v)
    {
        s += k / i;
        k %= i;
    }
    cout << s << endl;
}
