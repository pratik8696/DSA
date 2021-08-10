#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    int a=INT_MAX,b=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        a=min(a,array[i]);
        b=max(b,array[i]);
    }
    cout<<a<<" "<<b;
    return 0;
}
