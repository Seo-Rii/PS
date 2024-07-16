#include <ios>
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int n, t, v = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> t;
            v |= 1 << t;
        }
        else if (s == "remove")
        {
            cin >> t;
            v &= ~(1 << t);
        }
        else if (s == "check")
        {
            cin >> t;
            cout << (v & 1 << t ? 1 : 0) << '\n';
        }
        else if (s == "toggle")
        {
            cin >> t;
            v ^= 1 << t;
        }
        else if (s == "all") v = (1 << 21) - 1;
        else if (s == "empty") v = 0;
    }
}
