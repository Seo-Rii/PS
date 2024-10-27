#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<long long> w(N + 1), cnt(N + 1);
    for (int i = 1; i <= N - 1; i++) cin >> w[i];
    for (int i = 1; i <= M; i++)
    {
        long long u, v, x;
        cin >> u >> v >> x;
        cnt[u] += x;
        cnt[v] -= x;
    }
    for (int i = 1; i <= N; i++) cnt[i] += cnt[i - 1];
    for (int i = 1; i <= N - 1; i++)
    {
        long long c = cnt[i], v = w[i];
        if (c % v == 0) cout << (c / v) * (c / v) * v << '\n';
        else
        {
            long long n1 = c / v, n2 = c / v + 1;
            cout << n1 * n1 * (v - c % v) + n2 * n2 * (c % v) << '\n';
        }
    }
}
