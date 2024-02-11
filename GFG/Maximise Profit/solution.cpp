// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
// Position this line where user code will be pasted.

// Back-end complete function Template for C++

class Solution
{
public:
    int dp[101][101];
    int f(int l, int b, int n, vector<int> &a, vector<int> &p)
    {
        // cout<<l<<" "<<b<<endl;
        if (l <= 0 || b <= 0)
            return 0;
        int &fans = dp[l][b];
        if (fans != -1)
            return fans;

        int ans = 0;
        for (int i = 1; i < l; i++)
        {
            int x = f(l - i, b, n, a, p) + f(i, b, n, a, p);
            ans = max(ans, x);
        }
        for (int i = 1; i < b; i++)
        {
            int x = f(l, b - i, n, a, p) + f(l, i, n, a, p);
            ans = max(ans, x);
        }
        int A = l * b;
        for (int i = 0; i < n; i++)
        {
            if (A % a[i] == 0)
                ans = max(ans, p[i] * (A / a[i]));
        }
        return fans = ans;
    }
    int maxAmount(int l, int b, int n, vector<int> a, vector<int> p)
    {
        memset(dp, -1, sizeof(dp));
        return f(l, b, n, a, p);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, b, n;
        cin >> l >> b >> n;
        vector<int> a(n), p(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < n; j++)
            cin >> p[j];
        Solution obj;
        cout << obj.maxAmount(l, b, n, a, p) << endl;
    }
    return 0;
}