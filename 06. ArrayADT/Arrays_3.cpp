#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    int a=INT_MIN;
    int b=INT_MAX;
    for (int i = 0; i < k; i++)
    {
        a=max(a,array[i]);
        b=min(b,array[i]);
    }
    
    cout<<a<<" "<<b;


    return 0;
}