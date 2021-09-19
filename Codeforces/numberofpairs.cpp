#include <iostream>
using namespace std;

int main()
{
    int n,l,r,count=0;
    cin>>n>>l>>r;
    int arr[n];
    int hash_size=10000;
    int a[hash_size];
    // zeroes in hash table
    for (int i = 0; i < hash_size; i++)
    {
        a[i]=0;
    }
    // taking in input
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        a[arr[i]]++;
        int x = l - i;
        int y = r - i;

        for (; x <= y; x++)
        {
            if (a[x] != 0)
            {
                count++;
            }
        }
    }
    cout<<count<<endl;
    for (int i = 0; i < hash_size; i++)
    {
        cout<<a[i]<<" ";
    }   
}