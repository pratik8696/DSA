#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    getline(cin,name);
    int flag=0;
    for(int i=0,j=(name.length())-1;i<name.length();i++,j--)
    {
        if(name[i]!=name[j])
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        cout<<"Not palindrome";
    }
    else{
        cout<<"Its a palindrome";
    }
    return 0;
}