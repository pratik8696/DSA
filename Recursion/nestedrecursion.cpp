#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    if(n>0)
    {
        return n-10;
    }
    else
    {
        return fun(fun(n+11));
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<fun(n);
    return 0;
}