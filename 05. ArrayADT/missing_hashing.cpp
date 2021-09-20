#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int max=a[n-1];
    int hash[max]={0};
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    for (int i = 1; i < max; i++)
    {
        if (hash[i]==0)
        {
            cout<<i<<" ";
        }
        
    }
    return 0;
}