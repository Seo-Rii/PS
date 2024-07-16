#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s = 0, t = 0;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    for (auto& i : v) s += (t += i);
    cout << s << endl;
}
