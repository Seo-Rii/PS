//
// Created by 이서현 on 2024. 10. 26..
//
#include<iostream>
#include<climits>
using namespace std;
int a[3005][3005], b[3005][3005], md[3005];
int main()
{
    int n, m, ans = 0, t;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        md[i] = INT_MIN;
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>b[i][j];
            md[j] = max(md[j], abs(a[i][j] - b[i][j]));
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>t;
        ans += md[t - 1];
    }
    cout << ans << endl;
}