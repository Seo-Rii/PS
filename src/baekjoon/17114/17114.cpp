#include <ios>
#include <iostream>
#include <queue>

using namespace std;
int s[11], cnt, ans;
int r[1000005];

int w1[22] = {1, -1};
int w2[22] = {0, 0, 1, -1};
int w3[22] = {0, 0, 0, 0, 1, -1};
int w4[22] = {0, 0, 0, 0, 0, 0, 1, -1};
int w5[22] = {0, 0, 0, 0, 0, 0, 0, 0, 1, -1};
int w6[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};
int w7[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};
int w8[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};
int w9[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};
int w10[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};
int w11[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};

struct Data
{
    int p[11];
    int d;
};

int* at(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9, int x10, int x11)
{
    return &r[
        x1 +
        x2 * s[0] +
        x3 * s[0] * s[1] +
        x4 * s[0] * s[1] * s[2] +
        x5 * s[0] * s[1] * s[2] * s[3] +
        x6 * s[0] * s[1] * s[2] * s[3] * s[4] +
        x7 * s[0] * s[1] * s[2] * s[3] * s[4] * s[5] +
        x8 * s[0] * s[1] * s[2] * s[3] * s[4] * s[5] * s[6] +
        x9 * s[0] * s[1] * s[2] * s[3] * s[4] * s[5] * s[6] * s[7] +
        x10 * s[0] * s[1] * s[2] * s[3] * s[4] * s[5] * s[6] * s[7] * s[8] +
        x11 * s[0] * s[1] * s[2] * s[3] * s[4] * s[5] * s[6] * s[7] * s[8] * s[9]
    ];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<Data> q;
    for (auto& i : s) cin >> i;
    reverse(s, s + 11);
    for (int x1 = 0; x1 < s[0]; x1++)
        for (int x2 = 0; x2 < s[1]; x2++)
            for (int x3 = 0; x3 < s[2]; x3++)
                for (int x4 = 0; x4 < s[3]; x4++)
                    for (int x5 = 0; x5 < s[4]; x5++)
                        for (int x6 = 0; x6 < s[5]; x6++)
                            for (int x7 = 0; x7 < s[6]; x7++)
                                for (int x8 = 0; x8 < s[7]; x8++)
                                    for (int x9 = 0; x9 < s[8]; x9++)
                                        for (int x10 = 0; x10 < s[9]; x10++)
                                            for (int x11 = 0; x11 < s[10]; x11++)
                                            {
                                                auto pt = at(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11);
                                                cin >> *pt;
                                                if (*pt == 1)
                                                {
                                                    Data d;
                                                    d.p[0] = x1;
                                                    d.p[1] = x2;
                                                    d.p[2] = x3;
                                                    d.p[3] = x4;
                                                    d.p[4] = x5;
                                                    d.p[5] = x6;
                                                    d.p[6] = x7;
                                                    d.p[7] = x8;
                                                    d.p[8] = x9;
                                                    d.p[9] = x10;
                                                    d.p[10] = x11;
                                                    d.d = 0;
                                                    q.push(d);
                                                }
                                                if (!*pt) cnt++;
                                            }

    while (!q.empty())
    {
        auto [t, d] = q.front();
        for (int i = 0; i < 22; i++)
        {
            int nx1 = t[0] + w1[i];
            int nx2 = t[1] + w2[i];
            int nx3 = t[2] + w3[i];
            int nx4 = t[3] + w4[i];
            int nx5 = t[4] + w5[i];
            int nx6 = t[5] + w6[i];
            int nx7 = t[6] + w7[i];
            int nx8 = t[7] + w8[i];
            int nx9 = t[8] + w9[i];
            int nx10 = t[9] + w10[i];
            int nx11 = t[10] + w11[i];
            if (nx1 < 0 || nx1 >= s[0] || nx2 < 0 || nx2 >= s[1] || nx3 < 0 || nx3 >= s[2] || nx4 < 0 || nx4 >= s[3] ||
                nx5 < 0 || nx5 >= s[4] || nx6 < 0 || nx6 >= s[5] || nx7 < 0 || nx7 >= s[6] || nx8 < 0 || nx8 >= s[7] ||
                nx9 < 0 || nx9 >= s[8] || nx10 < 0 || nx10 >= s[9] || nx11 < 0 || nx11 >= s[10])
                continue;
            if (*at(nx1, nx2, nx3, nx4, nx5, nx6, nx7, nx8, nx9, nx10, nx11)) continue;
            *at(nx1, nx2, nx3, nx4, nx5, nx6, nx7, nx8, nx9, nx10, nx11) = 1;
            Data nd;
            nd.p[0] = nx1;
            nd.p[1] = nx2;
            nd.p[2] = nx3;
            nd.p[3] = nx4;
            nd.p[4] = nx5;
            nd.p[5] = nx6;
            nd.p[6] = nx7;
            nd.p[7] = nx8;
            nd.p[8] = nx9;
            nd.p[9] = nx10;
            nd.p[10] = nx11;
            nd.d = d + 1;
            q.push(nd);
            cnt--;
            ans = d + 1;
        }
        q.pop();
    }
    if (cnt) cout << -1;
    else cout << ans;
}
