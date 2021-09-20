#include <iostream>
using namespace std;

int fun(int n)
{
    if(n>0)
    {
        fun(n-1);
        cout<<n<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    fun(n);
    return 0;
}