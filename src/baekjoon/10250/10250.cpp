#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w, n, t;
    cin >> t;
    while (t--)
    {
        cin >> h >> w >> n;
        cout << ((n - 1) % h + 1) * 100 + (n - 1) / h + 1 << '\n';
    }
}
