#include<iostream>
#include<vector>
#include <string>

using namespace std;

int m, ar[1000004], br[1000004], ans[1000004];

int main()
{
    int i, j, k, flag=0;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, f = 0;
    cin >> n;
    string s;
    cin >> s;
    for(i=0; i<n; i++)
    {
        if(s[i]=='O') ar[i+1]=ar[i+1+n]=1, br[++m]=i+1;
    }
    if(!m)
    {
        printf("YES\n");
        for(i=1; i<=n; i++) printf("-");
        return 0;
    }
    br[++m]=br[1]+n;
    for(i=1; i<=m; i++)
    {
        if((br[i+1]-br[i])%2==1 && (br[i+1]-br[i])!=1)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        printf("NO\n");
        return 0;
    }
    for(i=1; ; i++)
    {
        if(ar[i]==1) break;
    }
    for(j=1; i<=n; i++)
    {
        ans[i]=2;
        for(k=1; k<=(br[j+1]-br[j]-1)/2; k++)
        {
            ans[++i]=2;
        }
        for(k=1; k<=(br[j+1]-br[j])/2; k++)
        {
            ans[++i]=1;
        }
        j++;
    }
    for(i=1; i<=n; i++)
    {
        if(ans[i]==0) ans[i]=ans[n+i];
    }
    printf("YES\n");
    for(i=1; i<=n; i++)
    {
        if(ans[i]==2) printf("+");
        else printf("-");
    }
    return 0;
}
