#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n==0||n==1)
    return 1;
    else{
        return factorial(n-1)*n;
    }
}


int fun(int n,int r)
{
    if(n==r||r==0)
    return 1;

    int p=factorial(n);
    int q=factorial(r);
    int t=factorial(n-r);

    return p/(q*t);
}

int main()
{
    int n,r;
    cin>>n>>r;
    cout<<fun(n,r);
    return 0;
}
