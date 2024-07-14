#include <ios>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<int, int> mp;
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        mp[t]++;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        cout << mp[t] << ' ';
    }
}
