#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, l, s = 0;
    cin >> n >> l;
    for (int i = 1; i < l; i++) s += i;
    for (int i = l; i <= 100; i++) {
        s += i;
        if ((n - s) % i == 0 && (n - s) / i >= -1) {
            for(int j = (n - s) / i; j < (n - s) / i + i; j++) {
                cout << j + 1 << " ";
            }
            return 0;
        }
    }
    cout << -1;
}