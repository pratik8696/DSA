#include <iostream>
using namespace std;

int fib(int n)
{
    if(n<=1)
    return n;

    else
    {
        return fib(n-1)+fib(n-2);
    }
}

int fibiterative(int n)
{
    static int t0=0,t1=1,sum=0,i=n-1;
    if(n<=1)
    return n;

    // for(int i=2;i<=n;i++)
    while(i--)
    {
        sum=t0+t1;
        t0=t1;
        t1=sum;
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    cout << fibiterative(n) << endl;
    return 0;
}