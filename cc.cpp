#include <bits/stdc++.h>
using namespace std;

int interestingArray(int n, int arr[], int x)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = __gcd(x, arr[i]);
        if (curr != 1)
        {
            ans += curr;
        }
        else
        {
            return -1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << interestingArray(n, arr, x) << endl;
    return 0;
}
