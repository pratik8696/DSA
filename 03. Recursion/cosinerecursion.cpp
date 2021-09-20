#include <bits/stdc++.h>
using namespace std;

int funcosi(int x,int n)
{
    static int s=1;
    for ( ; n >0; n--)
    {
        if(!(2*n-3<0))
        {
            s=1-(pow(x,2)/((2*n-3)*(2*n-2)))*s;
        }
        return s;
    }
}

int funcosr(int x,int n)
{
    static int q=1;
    if(2*n-3<0)
    return q;

    else{
        q=1-(pow(x,2)/((2*n-3)*(2*n-2)))*q;
        return funcosr(x,n-1);
    }
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<funcosi(x,n)<<endl;
    cout<<funcosr(x, n);
}