#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N, R, C;
char a[55][55];

int main()
{
    cin >> N >> R >> C;
    for (int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin >> a[i][j];

    vector<string> ans;
    if (R<=N/2)
    {
        for (int i=1; i<=R-1; i++) ans.push_back("U "+to_string(C)+" push"); //cout << "U " << C << " push\n";
        for (int i=1; i<=C-1; i++) ans.push_back("L "+to_string(1)+" push"); //cout << "L " << 1 << " push\n";
        for (int i=C+1; i<=N; i++) ans.push_back("R "+to_string(1)+" push"); //cout << "R " << 1 << " push\n";
        for (int i=2; i<=R; i++) ans.push_back("L "+to_string(i)+" pull"); //cout << "L " << i << " pull\n";

        for (int j=1; j<=N; j++)
        {
            int idx=1;
            for (int i=N; i>=2; i--) if (a[i][j]=='#')
            {
                idx=i;
                break;
            }
            for (int i=2; i<=idx; i++) ans.push_back("D "+to_string(j)+" push"); //cout << "D " << j << " push\n";
            for (int i=2; i<=idx; i++) if (a[i][j]=='.') ans.push_back("R "+to_string(i)+" pull"); //cout << "R " << i << " pull\n";
        }
        for (int j=1; j<=N; j++) if (a[1][j]=='.') ans.push_back("U "+to_string(j)+" pull"); //cout << "U " << j << " pull\n";
    }
    else
    {
        for (int i=R+1; i<=N; i++) ans.push_back("D "+to_string(C)+" push"); //cout << "U " << C << " push\n";
        for (int i=1; i<=C-1; i++) ans.push_back("L "+to_string(N)+" push"); //cout << "L " << 1 << " push\n";
        for (int i=C+1; i<=N; i++) ans.push_back("R "+to_string(N)+" push"); //cout << "R " << 1 << " push\n";
        for (int i=R; i<=N-1; i++) ans.push_back("L "+to_string(i)+" pull"); //cout << "L " << i << " pull\n";

        for (int j=1; j<=N; j++)
        {
            int idx=N;
            for (int i=1; i<=N-1; i++) if (a[i][j]=='#')
            {
                idx=i;
                break;
            }
            for (int i=N-1; i>=idx; i--) ans.push_back("U "+to_string(j)+" push"); //cout << "D " << j << " push\n";
            for (int i=N-1; i>=idx; i--) if (a[i][j]=='.') ans.push_back("R "+to_string(i)+" pull"); //cout << "R " << i << " pull\n";
        }
        for (int j=1; j<=N; j++) if (a[N][j]=='.') ans.push_back("D "+to_string(j)+" pull"); //cout << "U " << j << " pull\n";
    }
    cout << ans.size() << "\n";
    for (auto s: ans) cout << s << "\n";
}