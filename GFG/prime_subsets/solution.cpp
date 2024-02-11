#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

const int MOD = 1e9 + 7;
class Solution
{
public:
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    vector<int> getprime(int x)
    {
        vector<int> ans;
        for (auto t : primes)
        {
            int cc = 0;
            while (x % t == 0)
            {
                cc++;
                ans.push_back(t);
                x /= t;
            }
        }
        return ans;
    }

    long long sum(int idx, int mask, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (idx == arr.size())
        {
            return mask > 0;
        }

        auto &x = dp[idx][mask];
        if (x != -1)
        {
            return x;
        }

        long long ans = 0;
        // take it
        // find the factors
        vector<int> factors = getprime(arr[idx]);

        {
            bool flag = true;
            int new_mask = mask;

            for (auto t : factors)
            {
                int find_index = lower_bound(begin(primes), end(primes), t) - begin(primes);
                int result = new_mask & (1 << find_index);
                if (result > 0)
                {
                    flag = false;
                    break;
                }
                new_mask |= (1 << find_index);
            }

            if (flag)
            {
                ans += sum(idx + 1, new_mask, arr, dp);
                ans %= MOD;
            }
        }

        // leave it
        ans += sum(idx + 1, mask, arr, dp);
        ans %= MOD;
        return x = ans;
    }

    int primeSubsets(int N, vector<int> &Arr)
    {
        vector<vector<int>> dp(N + 1, vector<int>(1025, -1));
        return sum(0, 0, Arr, dp);
    }
};

int main()
{
    freopen("1input.txt", "r", stdin);
    freopen("1output.txt", "w", stdout);
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        vector<int> Arr(N);
        Array::input(Arr, N);

        char x;
        cin >> x;

        Solution obj;
        int res = obj.primeSubsets(N, Arr);

        cout << res << endl;
        cout << "~" << endl;
    }
}
