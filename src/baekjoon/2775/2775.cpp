#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;
int arr[17][17];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= 15; i++) arr[0][i] = i;
    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= 15; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                arr[i][j] += arr[i - 1][k];
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        int k, n;
        cin >> k >> n;
        cout << arr[k][n] << '\n';
    }
}
