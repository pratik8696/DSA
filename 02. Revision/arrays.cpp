#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    // int array[n];
    // for(i=0;i<n;i++)
    // {
    //     cin>>array[i];
    // }
    // cout<<"This is the input array"<<endl;
    //////////////////////////////////////Normal traversal of an array////////////////////////////////////////////////
    // for (i = 0; i < n; i++)
    // {
        // cout can also be in this form as array is actually a pointer to the first number 
        // and here we have derefrenced it as *(a+i)
    //     cout<< &array[i]<<" ";
    // }
    //////////////////////////////////////Array inside heap///////////////////////////////////////////////////////////
    // int *p;
    // int *q;
    // p=new int[n];
    // q=(int*)malloc(5*sizeof(int));
    // for(i=0;i<n;i++)
    // {
    //     cin>>p[i];
    // }
    // for ( i = 0; i < n; i++)
    // {
    //     cout<<p[i]<<" ";
    // }
    // so here we can dynamically store arrays in heap by using a pointer to point at that location and afterwards 
    // using the same pointer to traverse the array similar to a normal array i.e if int *p; and p=new int[n] 
    // then we can traverse as p[0],p[1],p[2] etc
    // for (i = 0; i < n; i++)
    // {
    //     cin >> q[i];
    // }
    // cout<<"Here are the contents of q"<<endl;
    // for (i = 0; i < n; i++)
    // {
    //     cout << q[i] << " ";
    // }
    // we can also use malloc too here malloc is used and its format is like malloc((no of spaces of int)*(size of an integer));
    // here i have used int u can use any data type u want


    // //////////////////////////////////////removing memory stored in heap//////////////////////////////////////////

    // we can use the keywords like (delete[]p;) this will deallocate the heap storage and the pointer p will become a
    // dangling pointer

    // here's an example
    // on increasing size of heap and also to copy values

    // int *r;
    // r=new int[2*n];

    // // now we will copy contents of q ptr to r ptr;

    // cout<<"Here are the content of r"<<endl;
    // for ( i = 0; i < n; i++)
    // {
    //     r[i]=q[i];
    // }

    // // here's the output of new ptr r

    // for ( i = 0; i < n; i++)
    // {
    //     cout<<r[i]<<" ";
    // }

    // //  now deleting memory

    // delete []p;
    // delete []q;

    // /////////////////////////////////now ptr to ptr to heap////////////////////////////////////////////
    // here we have to use double ptr
    int **t;
    int *w;
    t=&w;
    int y;
    cout<<w<<" "<<&w<<" "<<y;

}