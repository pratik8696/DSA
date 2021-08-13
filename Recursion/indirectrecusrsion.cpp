#include <iostream>
using namespace std;

void fun(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        sun(n-1);
    }
    
}

void sun(int n)
{
    if(n>1)
    {
    cout<<n<<" ";
    fun(n/2);
    }
}

int main()
{
    int n;
    cin>>n;
    fun(n);
}