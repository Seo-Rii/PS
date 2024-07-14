#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string r;
    vector<string> v(n);
    for (auto& i : v) cin >> i;
    for (int i = 0; i < v[0].size(); i++)
    {
        char c = v[0][i];
        bool f = true;
        for (int j = 1; j < n; j++)
        {
            if (c != v[j][i]) f = false;
        }
        r += f ? c : '?';
    }
    cout << r << '\n';
}
