#include<iostream>
#include<vector>

using namespace std;

bool arr[52][52], u[51];
int n, c, v[51];
vector<int> ans;

bool is_prime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool dfs(int l) {
    if (l == n) {
        ans.push_back(c);
        return true;
    }
    if (u[l]) {
        return dfs(l + 1);
    }
    u[l] = true;
    bool fl = false;
    for (int i = l + 1; i < n; i++) {
        if (arr[l][i] && !u[i]) {
            u[i] = true;
            if (l == 0) c = v[i];
            fl = dfs(l + 1);
            u[i] = false;
        }
        if (fl && l) break;
    }
    u[l] = false;
    return fl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            arr[i][j] = is_prime(v[i] + v[j]);
        }
    }
    dfs(0);
    sort(ans.begin(), ans.end());
    for (auto &i: ans) cout << i << ' ';
    if (ans.empty()) cout << -1;
}