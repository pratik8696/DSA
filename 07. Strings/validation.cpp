#include <iostream>
using namespace std;

int valid(string username)
{
    for (int i = 0; username[i] != '\0'; i++)
    {
        if (!(username[i] >= 65 && username[i] <= 90) && !(username[i] >= 97 && username[i] <= 122) && !(username[i] >= 48 && username[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string username;
    cin>>username;
    if (valid(username))
    {
        cout<<"Valid String"<<endl;
    }
    else{
        cout << "Invalid String" << endl;
    }
    return 0;
}