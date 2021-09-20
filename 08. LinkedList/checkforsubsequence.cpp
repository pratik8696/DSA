#include <iostream>
using namespace std;

int check(string s1,string s2)
{
    int i=0,j=0;
    while(j<s2.length())
    {
        if (s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    // if second string reaches its last index then its true 
    if(j==s2.length()-1)
    {return 1;}
    return -1;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(check(s1,s2))
    {
        cout<<"Strings are Anagram"<<endl;
    }
    else{
        cout<<"Strings are not Anagram"<<endl;
    }
    return 0;
}