//
// Created by 이서현 on 2022/05/22.
//
#include<iostream>
#include <vector>
#include <utility>
#include<set>

using namespace std;
using pii = pair<int, int>;

int main() {
    int n, ma = 0;
    cin >> n;
    vector<pii> v(n);
    set<pii> st;
    for (auto &i: v) cin >> i.first >> i.second;
    for (auto &i: v) st.insert(i);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int dx = v[j].first - v[i].first, dy = v[i].second - v[j].second;
            pii p1 = pii(v[j].first - dy, v[j].second - dx);
            pii p2 = pii(v[i].first - dy, v[i].second - dx);
            pii p3 = pii(v[j].first + dy, v[j].second + dx);
            pii p4 = pii(v[i].first + dy, v[i].second + dx);
            if ((st.find(p1) != st.end() && st.find(p2) != st.end() && p1 != v[i] && p1 != v[j] && p2 != v[i] &&
                 p2 != v[j]) ||
                (st.find(p3) != st.end() && st.find(p4) != st.end() && p3 != v[i] && p3 != v[j] && p4 != v[i] &&
                 p4 != v[j]))
                ma = max(ma, abs(2 * dx * dy) + (abs(dx) - abs(dy)) * (abs(dx) - abs(dy)));
        }
    }
    cout << ma << endl;
}