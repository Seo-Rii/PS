#include <ios>
#include <iostream>
#include <vector>

using namespace std;
long long MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto& i : v) cin >> i;
    long long s = 0;
    for (auto& i : v) s += i;
    s %= MOD;
    long long r = s * s;
    for (auto& i : v)
    {
        r -= i * i;
        while (r < 0) r += MOD;
        r %= MOD;
    }
    if (r % 2) r += MOD;
    cout << r / 2 % MOD << endl;
}
