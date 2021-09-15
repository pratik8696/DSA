#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int x;
    cin >> x;
    int north=(x % 4 ) == 0;
    if (north)
    {
        cout << "North" << endl;
    }
    else if ((x + 1) % 4 == 1)
    {
        cout << "East" << endl;
    }
    else if ((x + 2) % 4 == 2)
    {
        cout << "South" << endl;
    }
    else
    {
        cout << "West" << endl;
    }
    }
    return 0;
}