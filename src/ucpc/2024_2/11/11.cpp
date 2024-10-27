#include<stdio.h>
#include <__algorithm/comp_ref_type.h>

using namespace std;
typedef long long ll;

int n;
ll fr[600004], mr[600004], ans[200004];
const ll mod = 998244353;

ll euclid(ll r1, ll r2)
{
    ll t1=1, t2=0, t3, r3;
    while((r3=r1%r2))
    {
        t3=t1-t2*(r1/r2);
        r1=r2, r2=r3, t1=t2, t2=t3;
    }
    t2=(t2%mod+mod)%mod;
    return t2;
}

void solve()
{
    int i, j;
    fr[0]=1, mr[0]=euclid(fr[0], mod);
    for(i=1; i<=n*3; i++)
    {
        fr[i]=(fr[i-1]*i)%mod;
        mr[i]=euclid(fr[i], mod);
    }
    for(i=1; i<=n; i++)
    {
        j=i-1;
        ans[i]=fr[n-j]*fr[n-j]%mod;
        ans[i]=ans[i]*fr[n]%mod*mr[n-j]%mod*mr[j]%mod;
        ans[i]=ans[i]*(ll)((n-j)*2+j-1)%mod*euclid((n-j)*2-1, mod)%mod;
    }
}

int main()
{
    int i;
    scanf("%d", &n);
    solve();
    printf("%d\n", n);
    for(i=1; i<=n; i++)
    {
        printf("%d %lld\n", i, ans[i]);
    }
}
