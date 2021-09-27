#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define MAX 100

int main()
{
    fast_cin();
    int n;
    cin >> n;
    int arr[n];
    int hash[MAX];
    fill(hash,hash+MAX,0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash[arr[i]]++;
    }
    int s = arr[0];
    int e = arr[n - 1];
    for (int i = s; i <= e; i++)
    {
        if (hash[i] == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}