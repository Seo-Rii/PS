#include <ios>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (auto& c : s)
    {
        if ('A' <= c && c <= 'Z') c += 'a' - 'A';
        else c -= 'a' - 'A';
        cout << c;
    }
}
