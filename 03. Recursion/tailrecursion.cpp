#include <iostream>
using namespace std;
// Tail recursion
int fun(int n)
{
    if(n>0)
    {
        cout<<n<<endl;
        fun(n-1);
    }
}

int main(){
    int n;
    cin>>n;
    fun(n);
    return 0;
}