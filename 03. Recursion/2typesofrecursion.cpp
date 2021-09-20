#include <iostream>
using namespace std;

void returnwhileascending(int n)
{
    if (n>0)
    {
        cout<<n<<" ";
        returnwhileascending(n-1);
    }
    // cout <<"This is being printed while function is returning--- "<<n<<endl;
}

void returnafterascending(int n)
{
    if(n>0)
    {
        returnafterascending(n-1);
        cout<<n<<" ";
    }
}
int main(){ 
    int n;
    cin>>n;
    returnwhileascending(n);
    cout<<endl;
    returnafterascending(n);
    return 0;
}