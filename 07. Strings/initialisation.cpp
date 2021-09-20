#include <iostream>
using namespace std;
/* 
    A-65    a-97    0-48
    B-66    b-98    1-49
    ....    ....    ....
    ....    ....    ....
    ....    ....    ....
    ....    ....    ....
    ....    ....    ....
    Z-90    Z-122   9-57
*/
int main()
{
    
    char name[]="HelloThere";
    int i;
    for(i=0;name[i]!='\0';i++)
    {}
    cout<<"The length of the word "<<name<<" is "<<i<<endl;
    // now changing the case of the string
    for ( i = 0; i < name[i]!='\0'; i++)
    {
        if (name[i]>=65&&name[i]<=90)
        {
            name[i]+=32;
        }
        else if(name[i]>=97 && name[i]<=122)
        {
            name[i]-=32;
        }
    }   
    cout<<"The string after reversing the cases are "<<name;
    return 0;
}