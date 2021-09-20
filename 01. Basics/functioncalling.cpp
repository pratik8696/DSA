#include <iostream>
using namespace std;

int swapbyvalue(int x,int y)
{
    int temp=x;
    x=y;
    y=temp;
}
int swapbyaddress(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
int swapbyreference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main(){
    int a,b;
    cin>>a>>b;
    int a1=a,b1=b;
    swapbyvalue(a,b);
    cout<<a<<" "<<b<<endl;
    a = a1, b = b1;
    swapbyaddress(&a, &b);
    cout << a << " " << b << endl;
    a = a1, b = b1;
    swapbyreference(a, b);
    cout << a << " " << b << endl;
    a = a1, b = b1;
    return 0;
}