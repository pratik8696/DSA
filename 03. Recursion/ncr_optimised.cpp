#include <iostream>
using namespace std;
int fun(int n,int r)
{
    if(n==r||r==0)
    {
        return 1;
    }
    if(r==1||r==(n-1))
    {
        return n;
    }
    else{
        return fun(n-1,r-1)+fun(n-1,r);
    }
}

int main()
{
    int n,r;
    cin>>n>>r;
    cout<<fun(n,r);
    return 0;
}