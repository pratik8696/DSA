#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int hash[10000]={0};
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    sort(a,a+n);
    int start=a[0];
    int max=a[n-1];
    for (int i = start; i <= max; i++)
    {
        if (hash[i]>1)
        {
            cout<<i<<" ";
        }
        
    }
    return 0;
}