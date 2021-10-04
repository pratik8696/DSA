#include <iostream>
using namespace std;

void doublethearray(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i]=a[i]*2;
    }   
}

int *getarray(int n)
{
    int *p;
    p=(int*)malloc(n*sizeof(int));
    return p;
}

int *getpointertoarray(int *a,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return a;
}


int main(){
    int n;
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }

    int *q=getarray(n);
    int *i=getpointertoarray(array,n);
    
    cout<<endl;
    // now taking in array in heap;
    for (int i = 0; i < n; i++)
    {
        cin>>q[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << q[i]<<" ";
    }

    return 0;
}