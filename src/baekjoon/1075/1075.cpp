#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a = a / 100 * 100;
    for (int i = 0; i < 100; i++) {
        if ((a + i) % b == 0) {
            if (i < 10) cout << 0 << i;
            else cout << i;
            break;
        }
    }
}