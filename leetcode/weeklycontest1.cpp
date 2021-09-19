#include <bits/stdc++.h>
using namespace std;

int main()
{
    int value=0;
    vector<string> operations={"X++","++X","--X","X--"};
    for(int i=0;i<operations.size();i++)
    {
        if(operations[i]=="++X"||operations[i]=="X++")
        {
            value++;
        }
        else{
            value--;
        }
    }
    cout<<value;
}