#include <iostream>
using namespace std;

int fun(int n)
{
    if (n>0)
    {
        return fun(n-1)+n;
    }
    return 0;
}

int funstatic(int n)
{
    // static int is similar to global variable
    static int x;
    if (n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    
}

int main()
{
    int n;
    cin>>n;
    cout<<fun(n);
    cout<<endl<<funstatic(n);
    return 0;
}