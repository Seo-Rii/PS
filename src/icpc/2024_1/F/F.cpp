//
// Created by 이서현 on 2024. 10. 26..
//
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
using ld = long double;
using pii = pair<int, int>;
vector<pii> v;
pii p1, p2;
ld pi = 3.1415926535897932384626l;

bool meet(int a, int b, pii p)
{
    ld md = (ld)(a + b) / 2.0l;

    int di = abs(a - b);
    if (di == 1800) return true;
    if (di > 1800)
    {
        di = 3600 - di;
        if (md < 1800)
            md += 1800;
        else
            md -= 1800;
    }
    ld m = (ld)di / 2.0l;
    ld h = cosl(m / 1800l * pi) * 1000l;
    ld d = h / cosl((p.first - md) / 1800l * pi);
    if (d < 0) return false;
    return (ld)p.second >= d;
}

int main()
{
    int n, m, f;
    cin >> n;
    v.resize(n);
    for (auto& i : v)
    {
        cin >> i.first >> i.second;
    }
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        int di = abs(v[i].first - v[i].second);
        if (di == 1800)
        {
            int a = v[i].first;
            int b = v[i].second;
            if(a>b) swap(a, b);
            bool t1 = a<p1.first && p1.first<b;
            bool t2 = a<p2.first && p2.first<b;
            if(t1!=t2) s++;
            // f=0;
            // pair<int, int> a=p1, b=p2;
            // if(a.first>b.first) swap(a, b);
            // if(p1.first < p2.first)
            // {
            //     if(p1.first < v[i].first && v[i].first < p2.first) f=1;
            // }
            // else
            // {
            //
            // }
            // s+=f;
        } else
        {
            if (meet(v[i].first, v[i].second, p1)) s++;
            if (meet(v[i].first, v[i].second, p2)) s++;
        }
    }
    cout << ((s % 2) ? "NO" : "YES");
}
