#include <iostream>
using namespace std;

// common lene wla rule is horner's rule

int funrecursive(int x,int n)
{

    static int s=1;

    if(n==0)
    return s;

    else{
        s=1+x/n*s;
        return funrecursive(x,n-1);
    }
    
}

int funiterative(int x,int n)

{
    static int q=1;
    for (; n > 0; n--)

    {
        q=1+x/n*q;

    }

    return q;
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<funrecursive(x,n)<<endl;
    cout<<funiterative(x,n)<<endl;
    return 0;
}