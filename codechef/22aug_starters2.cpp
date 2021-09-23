#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        for(int i=0;i<N;i++)
        {
            if(i==0||i==(N-1))
            { cout<<"3";}
            else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
    return 0;
}