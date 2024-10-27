#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int N, a[105][105]={}, A[105][105];

int solve(int x)
{
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) A[i][j]=a[i][j];
    int cnt=0;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            if (j+1<=N && A[i][j]<=x && A[i][j+1]<=x)
            {
                cnt++;
                A[i][j]=1e9;
                A[i][j+1]=1e9;
            }
            else if (i+1<=N && A[i][j]<=x && A[i+1][j]<=x)
            {
                cnt++;
                A[i][j]=1e9;
                A[i+1][j]=1e9;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> a[i][j];

    for (int i=1; i<=N*N/2; i++)
    {
        int lo=1, hi=N*N;
        while (lo<hi)
        {
            int mid=(lo+hi)/2;
            int res=solve(mid);
            if (res>=i) hi=mid;
            else lo=mid+1;
        }
        cout << lo << "\n";
    }
}
