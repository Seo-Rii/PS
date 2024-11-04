#include<iostream>
#include<vector>

using namespace std;

vector<int> odd, even, ans;
int n, on, en, c;
bool npr[2005], u[55];

void make_prime() {
    npr[0] = npr[1] = true;
    for (int i = 2; i <= 1000; i++) {
        if (npr[i]) continue;
        for (int j = i * 2; j <= 2000; j += i) {
            npr[j] = true;
        }
    }
}

bool dfs(int l) {
    if (l == on) {
        ans.push_back(c);
        return true;
    }
    for (int i = 0; i < en; i++) {
        if (!u[i] && !npr[odd[l] + even[i]]) {
            bool fl = false;
            u[i] = true;
            fl = dfs(l + 1);
            u[i] = false;
            if (fl) return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    int t, f;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t % 2) odd.push_back(t);
        else even.push_back(t);
        if (i == 0) f = t;
    }
    if (f % 2 == 0) swap(odd, even);
    on = odd.size();
    en = even.size();
    if (on != en) {
        cout << -1;
        return 0;
    }

    make_prime();
    for (int i = 0; i < en; i++) {
        if (!u[i] && !npr[odd[0] + even[i]]) {
            u[i] = true;
            c = even[i];
            dfs(1);
            u[i] = false;
        }
    }
    sort(ans.begin(), ans.end());
    for (auto &i: ans) cout << i << ' ';
    if (ans.empty()) cout << -1;
    return 0;
}