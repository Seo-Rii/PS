#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x[30] = {0}, t;
    for (int i = 0; i < 28; i++)
    {
        cin >> t;
        x[t - 1] = 1;
    }
    for (int i = 0; i < 30; i++) if (!x[i]) cout << i + 1 << endl;
}
