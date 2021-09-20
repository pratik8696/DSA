#include <bits/stdc++.h>
using namespace std;
int main()
{        
    // the arrays must be sorted to use this method
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int m;
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    //code for union//
    sort(arr,arr+m);sort(array,array+n);
    int i = 0, j = 0, k = 0;
    // int a[n + m];
    // while (i < n && j < m)
    // {
    //     if (array[i] > arr[j])
    //     {
    //         a[k++] = arr[j++];
    //     }
    //     else if (array[i] < arr[j])
    //     {
    //         a[k++] = array[i++];
    //     }
    //     else if(array[i]==arr[j])
    //     {
    //         a[k++] = array[i++];
    //         j++;
    //     }
    // }
    // for (i; i < n; i++)
    // {
    //     a[k++] = array[i];
    // }

    // for (j; j < m; j++)
    // {
    //     a[k++] = arr[j];
    // }
    // // output
    // for (int i = 0; i < k; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // intersection
    i=j=k=0;
    int a1[max(n,m)];
    while (i < n && j < m)
    {
        if (array[i]>arr[j])
        {
            j++;
        }
        else if (array[i]<arr[j])
        {
            i++;
        }
        else if(array[i]==arr[j])
        {
            a1[k++] = array[i++];
            j++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << a1[i] << " ";
    }
    return 0;
}