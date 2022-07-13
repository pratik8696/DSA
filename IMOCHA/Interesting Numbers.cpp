#include <bits/stdc++.h>
using namespace std;

int interestingNumbers()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int lcm = arr[0];
    for (int i = 1; i < n; i++)
    {
        lcm = (lcm * arr[i]) / __gcd(lcm, arr[i]);
    }
    return lcm;
}

int main()
{
    cout<<interestingNumbers();
    return 0;
}
