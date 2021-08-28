#include <bits/stdc++.h>
using namespace std;
int main(){
    int *n=new int[5];
    int *m=new int[10];
    for (int i = 0; i < 5; i++)
    {
        cin>>n[i];
    }
    
    for (int i = 0; i < 5; i++)
    {
        m[i]=n[i];
    }
    delete []n;
    // and
    n=m;
    // and
    m=NULL;
    cout<<"The output array is"<<endl;
    n[5] = 4;
    n[6] = 4;
    n[7] = 4;
    for (int i = 0; i < 8; i++)
    {
        cout<<n[i]<<" ";
    }    
    return 0;
}