#include <stdio.h>
#include <vector>
#include <algorithm>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, q, vs, ans[300004], dt[300004], in[300004], ot[300004];
int pr[300004][24], ln[300004][24];
pii qr[300004];
vector<int> lk[300004];
struct Data
{
    pii a, b, c;
    Data(){}
    Data(pii na, pii nb, pii nc)
    {
        a=na, b=nb, c=nc;
    }
    Data operator+(const Data &r) const
    {
        pii ar[6];
        ar[0]=a, ar[1]=b, ar[2]=c, ar[3]=r.a, ar[4]=r.b, ar[5]=r.c;
        sort(ar, ar+6);
        return Data(ar[3], ar[4], ar[5]);
    }
}dp[300004][2];

struct Tree
{
    Data t[300000*4];
    void update(int p, Data v, int s=1, int e=300000, int num=1)
    {
        if(e<p || p<s) return;
        else if(p==s && e==p)
        {
            t[num]=v;
            return;
        }
        int md=(s+e)/2;
        update(p, v, s, md, num*2), update(p, v, md+1, e, num*2+1);
        t[num]=t[num*2]+t[num*2+1];
    }
    Data get_max(int l, int r, int s=1, int e=300000, int num=1)
    {
        if(e<l || r<s) return Data();
        else if(l<=s && e<=r) return t[num];
        int md=(s+e)/2;
        return get_max(l, r, s, md, num*2)+get_max(l, r, md+1, e, num*2+1);
    }
}tr;

void dfs1(int p)
{
    in[p]=++vs;
    for(auto i:lk[p])
    {
        if(dt[i]) continue;
        dt[i]=dt[p]+1, pr[i][0]=p, ln[i][0]=1;
        dfs1(i);
    }
    ot[p]=vs;
}

Data dfs2(int p)
{
    Data rv;
    rv.a=make_pair(0, p);
    for(auto i:lk[p])
    {
        if(dt[i]<dt[p]) continue;
        rv=rv+dfs2(i);
    }
    if(rv.a.se) rv.a.fi++;
    if(rv.b.se) rv.b.fi++;
    if(rv.c.se) rv.c.se++;
    dp[p][0]=rv;
    return rv;
}

pii tp[9];

Data dfs3(int p)
{
    int j;
    Data rv;
    for(j=0; j<9; j++) tp[j]=make_pair(0, 0);
    tp[6]=dp[p][1].a, tp[7]=dp[p][1].b, tp[8]=dp[p][1].c;
    for(auto i:lk[p])
    {
        if(dt[i]<dt[p]) continue;
        rv=dp[i][0];
        if(rv.a.se) rv.a.fi++;
        if(rv.b.se) rv.b.fi++;
        if(rv.c.se) rv.c.se++;
        tp[0]=rv.a;
        tp[1]=rv.b;
        tp[2]=rv.c;
        sort(tp, tp+9);
    }
    for(auto i:lk[p])
    {
        if(dt[i]<dt[p]) continue;
        for(j=0; j<9; j++)
        {
            if(tp[j].se==i) tp[j]=make_pair(0, 0);
        }
        sort(tp, tp+9);
        rv=Data(tp[6], tp[7], tp[8]);
        if(rv.a.se) rv.a.fi++;
        if(rv.b.se) rv.b.fi++;
        if(rv.c.se) rv.c.se++;
        dp[i][1]=rv;
        rv=dp[i][0];
        if(rv.a.se) rv.a.fi++;
        if(rv.b.se) rv.b.fi++;
        if(rv.c.se) rv.c.se++;
        tp[0]=rv.a;
        tp[1]=rv.b;
        tp[2]=rv.c;
        sort(tp, tp+9);
    }
    for(auto i:lk[p])
    {
        if(dt[i]<dt[p]) continue;
        dfs3(i);
    }
}

pii lca(int a, int b)
{
    int i;
    pii rv=make_pair(0, 0);
    if(dt[a]>dt[b]) swap(a, b);
    for(i=20; i>=0; i--)
    {
        if(dt[pr[b][i]]<dt[a]) continue;
        rv.se+=ln[b][i];
        b=pr[b][i];
    }
    if(a==b)
    {
        rv.fi=a;
        return rv;
    }
    for(i=20; i>=0; i--)
    {
        if(pr[a][i]==pr[b][i]) continue;
        rv.se+=ln[a][i], rv.se+=ln[b][i];
        a=pr[a][i], b=pr[b][i];
    }
    rv.se+=ln[a][0];
    rv.fi=pr[a][0];
    return rv;
}

void solve()
{
    int i, j;
    pr[1][0]=dt[1]=1;
    dfs1(1);
    dfs2(1);
    dfs3(1);
    for(i=1; i<=20; i++)
    {
        for(j=1; j<=n; j++)
        {
            pr[j][i]=pr[pr[j][i-1]][i-1];
            ln[j][i]=ln[pr[j][i-1]][i-1]+ln[pr[j][i]][i-1];
        }
    }
    for(i=1; i<=n; i++)
    {
        tr.update(in[i], dp[i][0]+dp[i][1]);
    }
    for(i=1; i<=q; i++)
    {
        pii rv=lca(qr[i].fi, qr[i].se);
        ans[i]=rv.se;
        Data st=tr.get_max(in[rv.fi], ot[rv.fi]);
        int a=qr[i].fi, b=qr[i].se;
        if((in[a]<in[st.c.se] || ot[st.c.se]<in[a]) && (in[b]<in[st.c.se] || ot[st.c.se]<in[b]))
        {
            ans[i]+=st.c.fi;
        }
        else if((in[a]<in[st.b.se] || ot[st.b.se]<in[a]) && (in[b]<in[st.b.se] || ot[st.b.se]<in[b]))
        {
            ans[i]+=st.b.fi;
        }
        else ans[i]+=st.c.fi;
    }
}

int main()
{
    int i, a, b;
    scanf("%d", &n);
    for(i=1; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        lk[a].push_back(b);
        lk[b].push_back(a);
    }
    scanf("%d", &q);
    for(i=1; i<=q; i++)
    {
        scanf("%d %d", &qr[i].fi, &qr[i].se);
    }
    solve();
    for(i=1; i<=q; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}