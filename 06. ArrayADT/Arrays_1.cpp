#include <iostream>
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
  for (int i=0;i<n;i++)
  {
    cin>>array[i];
  }
  for (int i=0,j=n-1;i<j;i++,j--)
  {
      swap(&array[i],&array[j]);
  }
  for (int i=0;i<n;i++)
  {
    cout<<array[i]<<" ";
  }
  return 0;
}
// 2nd method is by creating a new array
// int deleteElement(int arr[], int n, int x)
// {
// // Search x in array
// int i;
// for (i=0; i<n; i++)
//     if (arr[i] == x)
//         break;
 
// // If x found in array
// if (i < n)
// {
//     // reduce size of array and move all
//     // elements on space ahead
//     n = n - 1;
//     for (int j=i; j<n; j++)
//         arr[j] = arr[j+1];
// }
// }
