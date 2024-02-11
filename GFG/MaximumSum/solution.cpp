#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSum(int n, int k, int x)
    {
        if (k > n)
        {
            return -1;
        }
        if (k - 1 > x)
        {
            return -1;
        }
        int sum = k * (k - 1) / 2;
        int left = n - k;
        int mx = (x > k ? x : k - 1);
        int ans = sum + left * mx;
        return ans;
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

        int K;
        scanf("%d", &K);

        int X;
        scanf("%d", &X);

        Solution obj;
        int res = obj.maximumSum(N, K, X);
        char x;
        cin >> x;
        cout << res << endl;
        cout << "~" << endl;
    }
}
