#include <ios>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        l = 0;
        for (auto& c : str)
        {
            if (c == '(') l++;
            else l--;
            if (l < 0) break;
        }
        if (l == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
