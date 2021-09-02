#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int duplicate_element=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==arr[i+1]&&arr[i+1]!=duplicate_element)
        {
            cout<<arr[i]<<" ";
            duplicate_element=arr[i];
        }
    }
    return 0;
}