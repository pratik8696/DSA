#include <iostream>
using namespace std;
int main()
{
    string name;
    getline(cin,name);
    int i;
    // first fot finding the length of the string 
    for ( i = 0; name[i] !='\0'; i++)
    {
        // here we calculate the length of the string
    }
    i=i-1;
    int j;
    char temp;
    // here the reverse operation takes place
    for (i,j=0; j<i; i--,j++)
    {
        temp=name[j];
        name[j]=name[i];
        name[i]=temp;
    }
    cout<<name;
    return 0;
}