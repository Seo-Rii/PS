#include <ios>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<string> st, ans;
    string s;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        st.insert(s);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (st.find(s) != st.end()) ans.insert(s);
    }
    cout << ans.size() << '\n';
    for (auto& i : ans) cout << i << '\n';
}
