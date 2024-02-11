#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySumK(vector<int> &a, int n, int k)
    {
        vector<long long> pre(a.size() + 1);
        pre[1] = a[0];
        for (int i = 2; i <= a.size(); i++)
        {
            pre[i] += pre[i - 1] + a[i - 1];
        }
        deque<long long> dq;
        long long ans = 1e9;
        for (int i = 0; i < pre.size(); i++)
        {
            // calculate the answer
            while (dq.size() && pre[i] - pre[dq.front()] >= k)
            {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            // removing operation
            while (dq.size() && pre[i] <= pre[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return (ans == 1e9 ? -1 : ans);
    }
};

// Position this line where user code will be pasted.
int main()
{
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