#include <iostream>
#include <string>
using namespace std;

int duplicate(string name)
{
    for (int i = 0; i < name.length()-1; i++)
    {
        for (int j = i+1; j < name.length(); j++)
        {
            if(name[i]==name[j])
            {
                cout<<name[i]<<" Duplicate found"<<endl;
            }
        }
        
    }
}
int main()
{
    string n;
    cin>>n;
    duplicate(n);
    return 0;
}