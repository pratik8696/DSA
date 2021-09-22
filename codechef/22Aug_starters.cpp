#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {int arr[7];
    for (int i = 0; i < 7; i++)
    {
        cin>>arr[i];
    }
    
    int sunny=0,rainy=0;
    for (int i = 0; i < 7; i++)
    {
        if(arr[i]==0)
        {
            rainy++;
        }
        else{
            sunny++;
        }
    }
    if(sunny>rainy)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
    return 0;
}