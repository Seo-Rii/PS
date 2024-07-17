#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& [x, y] : v) cin >> x >> y;
    for (auto& [x, y] : v)
    {
        int rank = 1;
        for (auto& [x2, y2] : v) if (x < x2 && y < y2) rank++;
        cout << rank << ' ';
    }
}
