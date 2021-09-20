#include <iostream>
using namespace std;
int main(){
    int *p[3];
    for (int i = 0; i < 3; i++)
    {
        p[i]=new int[4];
    }
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>p[i][j];
        }
    }
    cout<<"The output is: "<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << p[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}