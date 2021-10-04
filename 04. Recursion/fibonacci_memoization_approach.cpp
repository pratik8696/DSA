#include <iostream>
using namespace std;

int fun(int n)
{
    static int A[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    if (n <= 1)
    {
        A[n] = n;
        return n;
    }

    else
    {
        if (A[n - 1] == (-1))
        {
            A[n - 1] = fun(n - 1);
        }

        if (A[n - 2] == (-1))
        {
            A[n - 2] = fun(n - 2);
        }

        return A[n - 1] + A[n - 2];
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<fun(n);
    return 0;
}