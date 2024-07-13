#include <iostream>
#include <string>

using namespace std;

void tc(int cn)
{
    cout << "Case #" << cn + 1 << endl;

    int n, cnt = 0, t = 0;
    string s;
    cin >> n >> s;
    if (s[0] == 'A') t = 2;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == 'A')
        {
            cnt += t;
            t = 3;
        }
        if (t) t--;
    }
    cout << cnt << endl;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) tc(i);
    return 0;
}
