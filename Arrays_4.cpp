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
    int k;
    cin>>k;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    //selection sorting is used here//
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (array[i]>array[j])
            {
                swap(&array[i],&array[j]);
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    











    return 0;
}   