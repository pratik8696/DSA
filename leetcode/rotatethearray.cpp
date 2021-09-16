#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int t = arr[n - 1];
    int i = n - 1;
    while (n >= 1)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = t;

    
    return 0;
}