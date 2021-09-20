#include <bits/stdc++.h>
using namespace std;

int swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int main(){
    int n;
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    //selection sorting is used here//
    int i=0,j=n-1;
    while (i<j)
    {
    while (array[i]>0)
    {
        i++;
    }
    while (array[j]<0)
    {
        j--;
    }
    if (i<j)
    {
        swap(&array[i],&array[j]);
    }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }

    return 0;
}   