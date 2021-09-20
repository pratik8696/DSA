#include <iostream>
using namespace std;
int compare(string a, string b)
{
    int i, j;
    i = j = 0;
    for (i, j; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i]!=b[j])
        {
            break;
        }
        
    }
    if (a[i]==b[j])
    {
        cout<<"Equal Strings";
    }
    else if(a[i]>b[j])
    {
        cout<<a<<" is greater than "<<b;
    }
    else if(a[i]<b[j])
    {
        cout<<b<<" is greater than "<<a;
    }
    
}

int main()
{
    // string n, m;
    // getline(cin, n);
    // getline(cin, m);
    // compare(n,m);
    // return 0;
    string a, b;
    getline(cin, a);
    getline(cin, b);
    // compare(n, m);
    int i, j;
    i = j = 0;
    for (i, j; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i] != b[j])
        {
            break;
        }
    }
    if (a[i] == b[j])
    {
        cout << "Equal Strings";
    }
    else if (a[i] > b[j])
    {
        cout << a << " is greater than " << b;
    }
    else if (a[i] < b[j])
    {
        cout << b << " is greater than " << a;
    }
}