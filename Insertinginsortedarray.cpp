#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int l;
    cin>>l;
    int array[n];
    for (int i = 0; i < l; i++)
    {
        cin>>array[i];
    }
    sort(array,array+l);
    cout<<"THE SORTED ARRAY IS = \n";
    for (int i = 0; i < l; i++)
    {
        cout<<array[i]<<" ";
    }
    int x;
    cin>>x;
    int i=n-1;
    while (x<array[i])
    {
        array[i+1]=array[i];
        i--;
    }
    array[i+1]=x;
    l++;
    cout<<"THE FINAL ARRAY IS = \n";
    for (int i = 0; i < l; i++)
    {
        cout<<array[i]<<" ";
    }
    
    return 0;
}