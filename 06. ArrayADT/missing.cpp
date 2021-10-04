#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int diff=arr[0];
    sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i]-i!=diff)
        {
            while (diff<arr[i]-i)
            {
                // most important step here is i+diff
                cout<<diff+i<<" ";
                diff++;
            }
        }
    }
    return 0;
}