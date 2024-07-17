#include <ios>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    while (true)
    {
        vector<char> stk;
        getline(cin, s);
        if (s == ".") break;
        for (auto& c : s)
        {
            if (c == '[') stk.push_back('[');
            else if (c == '(') stk.push_back('(');
            else if (c == ']')
            {
                if (stk.empty() || stk.back() != '[')
                {
                    stk.push_back('!');
                    break;
                }
                stk.pop_back();
            }
            else if (c == ')')
            {
                if (stk.empty() || stk.back() != '(')
                {
                    stk.push_back('!');
                    break;
                }
                stk.pop_back();
            }
        }
        cout << (stk.empty() ? "yes" : "no") << '\n';
    }
}
