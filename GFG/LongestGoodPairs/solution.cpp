#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestGoodPairs(int A, int B)
    {
        if (__gcd(A, B) != 1)
        {
            return 0;
        }
        int N = abs(A - B);
        int ans = N;
        for (int i = 2; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                ans = min(ans, i - 1 - (A - 1) % i);
                while (N % i == 0)
                {
                    N /= i;
                }
            }
        }
        return (ans == N ? -1 : ans);
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

        int A;
        scanf("%d", &A);

        int B;
        scanf("%d", &B);

        Solution obj;
        int res = obj.longestGoodPairs(A, B);
        char x;
        cin >> x;
        cout << res << endl;
        cout << "~" << endl;
    }
}
