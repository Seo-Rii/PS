#include <ios>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string name, type;
    int t, n, s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        s = 1;
        map<string, int> m;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> name >> type;
            m[type]++;
        }
        for (auto& [k, v] : m) s *= (v + 1);
        s--;
        cout << s << endl;
    }
}
