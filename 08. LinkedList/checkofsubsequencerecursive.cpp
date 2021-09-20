#include <iostream>
using namespace std;

int recursivecheck(string s1,string s2)
{
    static int i=0,j=0;
    if(i==s1.length()-1)
    return false;

    if(j==s2.length()-1)
    return true;

    if(s1[i]==s2[j])
    {
        i++;j++;
    return recursivecheck(s1,s2);
    }

        i++; 
        return recursivecheck(s1,s2); 

}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(recursivecheck(s1,s2))
    {
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}