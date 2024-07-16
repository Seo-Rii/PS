#include <ios>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, greater<>> pq;
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (!t)
        {
            if (pq.empty()) cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(t);
    }
}
