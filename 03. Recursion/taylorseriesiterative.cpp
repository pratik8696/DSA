#include <bits/stdc++.h>
using namespace std;

int iterative(int x,int n)
{
    static int s=1;
    for(;n>0;n--)
    {
        s=1+x/n*s;
    }
    return s;
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<iterative(x,n);
    return 0;
}
