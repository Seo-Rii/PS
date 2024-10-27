//
// Created by 이서현 on 2024. 10. 26..
//
#include<iostream>
#include<climits>
using namespace std;
int a, b, c, d, e, f, g, h, i, j, k, l, m;
int A, B, C, D, E, F, G, H, ans;

void solve()
{
    for(a=1; a<=13; a++)
    {
        for(b=1; b<=13; b++)
        {
            if(a==b) continue;
            for(e=1; e<=13; e++)
            {
                if(a==e || b==e) continue;
                for(f=1; f<=13; f++)
                {
                    if(a==f || b==f || e==f) continue;
                    for(k=1; k<=13; k++)
                    {
                        if(a==k || b==k || e==k || f==k) continue;
                        if(B!=a+b+e+f-k-A+H+G) continue;
                        if(F!=a+b+e+f-k-E+C+D) continue;
                        for(j=1; j<=13; j++)
                        {
                            if(a==j || b==j || e==j || f==j || k==j) continue;
                            m=B-b-f-j;
                            if(m<1 || m>13 || a==m || b==m || e==m || f==m || k==m || j==m) continue;
                            l=H-m;
                            if(l<1 || l>13 || a==l || b==l || e==l || f==l || k==l || j==l || m==l) continue;
                            i=A-a-e-l;
                            if(i<1 || i>13 || a==i || b==i || e==i || f==i || k==i || j==i || m==i || l==i) continue;
                            for(g=1; g<=13; g++)
                            {
                                if(a==g || b==g || e==g || f==g || k==g || j==g || m==g || l==g || i==g) continue;
                                h=F-e-f-g;
                                if(h<1 || h>13 || a==h || b==h || e==h || f==h || k==h || j==h || m==h || l==h || i==h || g==h) continue;
                                d=D-h;
                                if(d<1 || d>13 || a==d || b==d || e==d || f==d || k==d || j==d || m==d || l==d || i==d || g==d || h==d) continue;
                                c=E-a-b-d;
                                if(c<1 || c>13 || a==c || b==c || e==c || f==c || k==c || j==c || m==c || l==c || i==c || g==c || h==c || d==c) continue;
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin>>A>>B>>C>>D>>E>>F>>G>>H;
    solve();
    cout<<ans;
}