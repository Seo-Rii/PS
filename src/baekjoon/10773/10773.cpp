#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    int n, t, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t) v.push_back(t);
        else v.pop_back();
    }
    for (auto& i : v) s += i;
    cout << s << endl;
}
