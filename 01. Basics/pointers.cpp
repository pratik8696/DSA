#include <iostream>
using namespace std;

int byaddress(int *a, int *b)
{
    *a--;
    *b++;
    cout<<*a<<" "<<*b<<endl;
}

int main()
{
    int a = 81;
    int b = 9;
    byaddress(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}