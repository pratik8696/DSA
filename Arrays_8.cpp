#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,rot;
    cin>>n>>rot;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < rot; i++)
    {
    int x=arr[0];
    for (int i = 0; i <n-1 ; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=x;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}