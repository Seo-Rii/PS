//
// Created by 이서현 on 2024. 10. 26..
//
#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
#include<vector>
#define mk make_pair
#define fi first
#define se second

using namespace std;
typedef pair<int,int> pii;

priority_queue<pii> pq;
int n, m, ans;
int f[200004], c[200004], dp[200004];
char t[200004], p[200004];


void kmp()
{
    int i, j;
    for(i=2, j=1; i<=n; i++)
    {
        while(p[i]!=p[j] && j!=1)
        {
            j=f[j-1]+1;
        }
        if(p[i]==p[j]) f[i]=j++;
    }
    for(i=1, j=1; i<=n; i++)
    {
        while(t[i]!=p[j] && j!=1)
        {
            j=f[j-1]+1;
        }
        if(t[i]==p[j])
        {
            j++;
            if(j>m)
            {
                c[i]=1;
                j=f[j-1]+1;
            }
        }
    }
}

void solve()
{
    int i;
    pii sp, rp;
    pq.push(mk(-m, 0));
    for(i=1; i<=n; i++)
    {
        dp[i]=dp[i-1]+1;
        if(c[i])
        {
            rp.se=-1;
            while(!pq.empty())
            {
                sp=pq.top();
                //printf("%d %d %d\n", sp.fi, sp.se, i-m-1);
                if(sp.se<i-m)
                {
                    pq.pop();
                    continue;
                }
                rp=sp;
                break;
            }
            if(rp.se!=-1)
            {
                dp[i]=min(dp[i], -rp.fi-i);
            }
        }
        pq.push(mk(-(dp[i]+m+i), i));
    }
    ans=dp[n];
}

int main()
{
    int i;
    scanf("%d %d", &m, &n);
    scanf("%s %s", p+1, t+1);
    //n=strlen(t+1), m=strlen(p+1);
    kmp();
    solve();
    printf("%d\n", ans);
}