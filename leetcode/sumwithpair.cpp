#include <iostream>
using namespace std;
int main()
{
    int n,target;
    cin>>n>>target;
    int arr[n];
    int hash[1000];
    fill(hash,hash+1000,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if(hash[target-arr[i]]!=0)
        {
            cout<<hash
        }
    }
    
    
    return 0
}
