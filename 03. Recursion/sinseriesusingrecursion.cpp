#include <bits/stdc++.h>
using namespace std;

int funsini(int x,int n)
{
    static int s=1;
    for(;n>0;n--)
    {
        if(!(2*n-2==0)){
        s=1-(pow(x,2)/((2*n-2)*(2*n-1)))*s;
        }
    }
    return x*s;
}

int funsinr(int x,int n)
{
    static int q=1;
    if(2*n-2==0)
    return x*q;

    else{
        q = 1 + (pow(x, 2) / ((2 * n - 2) * (2 * n - 1)))*q;
        return funsinr(x,n-1);
    }
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<funsini(x,n)<<endl;
    cout << funsinr(x, n) << endl;
}