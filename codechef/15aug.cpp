#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
    int array[10];
    int first=0;
    int second=0;
    for (int i = 0; i < 10; i++)
    {
        cin>>array[i];
    }

    for (int i = 0; i < 10; i=i+2)
    {
        first=first+array[i];
    }
    for (int i = 1; i < 10; i=i+2)
    {
        second = second + array[i];
    }

    if(first>second)
    {
        cout<<"1"<<endl;
    }
    if (first < second)
    {
        cout << "2" << endl;
    }
    if (first == second)
    {
        cout << "0" << endl;
    }
    }
    return 0;
}