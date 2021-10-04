#include <bits/stdc++.h>
using namespace std;

int taylorseries(int x,int n)
{
    static int p,q=1;
    if(x==0)
    {
        return 1;
    }

    else
    {
        p=x*p;
        q=n*q;
        return taylorseries(x,n-1);
    }
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<taylorseries(x,n);
}