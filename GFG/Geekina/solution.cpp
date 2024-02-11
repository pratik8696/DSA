// Initial Template for C++

#include "bits/stdc++.h"
using namespace std;
// Position this line where user code will be pasted.
// Back-end complete function Template for C++

class Solution
{
public:
    vector<int> retrieveInitialArray(int ex_array[], int N, int K)
    {
        int cnt_k = 0;
        for (int i = 0; i < N; i++)
        {
            if (ex_array[i] == K)
                cnt_k++;
        }
        int sz = (N - cnt_k) / 2 + cnt_k;
        vector<int> ans;
        for (int i = 0; i < sz; i++)
            ans.push_back(ex_array[i]);
        return ans;
    }
};

int main()
{
    freopen("1000in.txt", "r", stdin);
    freopen("1000out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        char x;
        cin >> x;
        vector<int> ans = ob.retrieveInitialArray(a, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
        cout << "~" << endl;
    }
}
