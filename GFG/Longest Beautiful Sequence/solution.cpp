// Initial Template for C++

#include "bits/stdc++.h"
using namespace std;

// Back-end complete function Template for C++

class Solution
{
public:
    int longestBeautifulSequence(int A[], int N, int K)
    {
        int dp[N];
        long long int k = K;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++)
        {
            long long int curr_element = A[i];
            for (int j = 0; j < i; j++)
            {
                long long int prev_element = A[j];
                if ((curr_element * prev_element) % k == 0LL)
                {
                    if (dp[j] == 0)
                        dp[i] = max(dp[i], 2);
                    else
                        dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp, dp + N);
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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        char x;
        cin >> x;
        
        Solution ob;
        int ans = ob.longestBeautifulSequence(a, n, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
}