// Initial Template for C++

#include "bits/stdc++.h"
using namespace std;

// Back-end complete function Template for C++

class Solution
{
public:
    long long sweetsForRemaining(int remainingFriends, int prev, int k)
    {
        long long required = 0LL;
        while (remainingFriends != 0)
        {
            int curr_req = max(1, prev - k + 1);
            required += (long long)curr_req;
            prev = curr_req;
            remainingFriends--;
        }
        return required;
    }

    bool isPossibleToEat(int mid, int n, int m, int k, int x)
    {
        long long sweetsReq = mid;
        int leftFriends = x - 1;
        int rightFriends = n + 1 - x;
        sweetsReq += sweetsForRemaining(leftFriends, mid, k);
        sweetsReq += sweetsForRemaining(rightFriends, mid, k);
        return sweetsReq <= (long long)m;
    }

    int maxNumberOfSweets(int n, int m, int k, int x)
    {
        int ans = 0, lo = 1, hi = m;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (isPossibleToEat(mid, n, m, k, x))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    freopen("input1000.txt", "r", stdin);
    freopen("output1000.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, x;
        cin >> n >> m >> k >> x;
        Solution ob;
        int ans = ob.maxNumberOfSweets(n, m, k, x);
        cout << ans << endl;
    }
}