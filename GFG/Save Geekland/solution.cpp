#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution
{
public:
    ll sum(ll idx, ll rem, int p[], int d[], int c[], int n, int m, vector<vector<int>> &dp)
    {
        if (idx == m)
        {
            if (rem == 0)
                return 0;
            else
                return 1e9;
        }
        auto &x = dp[idx][rem];
        if (x != -1)
        {
            return x;
        }
        ll ans = 1e9;
        // take it
        if (rem - d[idx] >= 0)
        {
            ans = min(ans, sum(idx, rem - d[idx], p, d, c, n, m, dp) + c[idx]);
        }
        // don't take it
        ans = min(ans, sum(idx + 1, rem, p, d, c, n, m, dp));
        return x = ans;
    }

    int minimalCost(int n, int m, int p[], int d[], int c[])
    {
        int ans = 0;
        int maxn = 0;
        for (int i = 0; i < n; i++)
        {
            maxn = max(maxn, p[i]);
        }
        vector<vector<int>> dp(m + 1, vector<int>(maxn + 1, -1));
        for (int i = 0; i < n; i++)
        {
            int cost = sum(0, p[i], p, d, c, n, m, dp);
            if (cost == 1e9)
            {
                return -1;
            }
            ans += cost;
        }
        return ans;
    }
};

int main()
{
    freopen("10input.txt", "r", stdin);
    freopen("10output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int p[n], d[m], c[m];
        for (int i = 0; i < n; i++)
            cin >> p[i];
        for (int i = 0; i < m; i++)
            cin >> d[i];
        for (int i = 0; i < m; i++)
            cin >> c[i];

        char x;
        cin >> x;

        Solution ob;
        int ans = ob.minimalCost(n, m, p, d, c);
        cout << ans << endl;
        cout << "~" << endl;
    }
}