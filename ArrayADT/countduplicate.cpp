#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int j;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            j = i + 1;
            while (arr[i+1] == arr[i])
            {
                j++;
            }
            
        cout << arr[i] << " = " << j-i << endl;
        j = 0;
        }
    }
    return 0;
}