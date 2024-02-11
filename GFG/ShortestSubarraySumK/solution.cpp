#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySumK(vector<int> &a, int n, int k)
    {
        int i = 0, sum = 0, ans = 1e9;
        for (int j = 0; j < n; j++)
        {
            sum += a[j];
            while (i < j && sum - a[i] >= k)
            {
                sum -= a[i++];
            }
            if (sum >= k)
                ans = min(ans, j - i + 1);
        }
        return (ans == 1e9 ? -1 : ans);
    }
};

int main()
{
    freopen("1in.txt", "r", stdin);
    freopen("1out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        char x;
        cin >> x;
        Solution ob;
        int ans = ob.subarraySumK(a, n, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}