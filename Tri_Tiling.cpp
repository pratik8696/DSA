#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == -1)
    {
        exit(0);
    }
    if (n % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> dp(31);
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = (4 * dp[i - 2]) - dp[i - 4];
        }
    }
    cout << dp[n] << endl;
}

int main()
{
    int t = INT_MAX;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
