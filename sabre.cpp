#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
    map<pair<int, int>, int> m;
    for (int i = 0; i < n - 1; i++)
    {
        m[{arr[i], arr[i + 1]}]++;
    }
    set<pair<int, int>> res;
    for (auto t : m)
    {
        if (t.second > 1)
        {
            res.insert(t.first);
        }
    }
    for (auto t : res)
    {
        cout << t.first << " " << t.second << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
}