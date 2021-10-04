#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define MAX 100000

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int hash[MAX];
    fill(hash, hash + MAX, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash[arr[i]]++;
    }
    sort(arr,arr+n);
    int s = arr[0];
    int e = arr[n - 1];
    for (int i = s; i <= e; i++)
    {
        if (hash[i] > 1)
        {
            cout << i << " ---> "<<hash[i]<<endl;
        }
    }
    
    return 0;
}