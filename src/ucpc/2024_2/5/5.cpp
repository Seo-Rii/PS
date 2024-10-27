#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


ll c[400005]={}, x[400005]={}, pfs[400005]={};

int main()
{
    //cout << 18+23+18+15+13+11+37+23+21+10+4+9+7+71+92+4+2+40+1+55+19;
    int N; cin >> N;
    for (int i=1; i<=N; i++)
    {
        cin >> c[i];
        c[i+N]=c[i];
    }
    for (int i=1; i<=N; i++)
    {
        cin >> x[i];
        x[i+N]=x[i];
    }

    for (int i=1; i<=2*N; i++) pfs[i]=pfs[i-1]+x[i];

    ll ans1=0, prev=-1, type=-1, stop=-1;
    vector<ll> v;
    for (int i=1; i<=2*N; i++)
    {
        if (i==stop) break;

        if (c[i]!=0)
        {
            if (prev==-1)
            {
                stop=i+N+1;
                prev=i;
                type=c[i];
            }
            else
            {
                //cout << prev << ' ' << i << endl;
                if (c[i]==type && type==1)
                {
                    ans1+=pfs[i-1]-pfs[prev];
                }
                else if (c[i]!=type)
                {
                    ll cnt=i-prev-1;
                    if (type==1)
                    {
                        ans1+=pfs[prev+cnt/2]-pfs[prev];
                    }
                    else
                    {
                        ans1+=pfs[i-1]-pfs[i-1-cnt/2];
                    }
                    if (cnt%2) v.push_back(x[prev+cnt/2+1]);
                }
                prev=i;
                type=c[i];
            }
        }
    }
    if (stop==-1)
    {
        cout << "0 0\n";
        return 0;
    }
    sort(v.begin(), v.end());
    ll ans2=0;
    for (int i=1; i<=N; i++)
    {
        if (c[i]==1) ans1+=x[i];
        ans2+=x[i];
    }

    for (int i=v.size()-1; i>=0; i-=2) ans1+=v[i];
    ans2-=ans1;
    cout << ans1 << ' ' << ans2 << "\n";
}