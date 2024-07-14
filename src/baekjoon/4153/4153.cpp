#include <ios>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        if (!arr[0] && !arr[1] && !arr[2]) break;
        sort(arr, arr + 3);
        if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1]) cout << "right\n";
        else cout << "wrong\n";
    }
}
