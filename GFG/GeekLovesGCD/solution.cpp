#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long totient(long long n)
    {
        long long result = n;

        for (long long p = 2; p * p <= n; p++)
            if (n % p == 0)
            {
                result = result / p * (p - 1);

                do
                {
                    n /= p;
                } while (n % p == 0);
            }

        if (n > 1)
            result = result / n * (n - 1);

        return result;
    }

    long long geeksGcd(long long A, long long M)
    {
        long long G = __gcd(A, M);
        A /= G;
        M /= G;
        return totient(M);
    }
};

int main()
{
    freopen("1input.txt", "r", stdin);
    freopen("1output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, m;
        cin >> a >> m;
        char x;
        cin >> x;
        Solution s;
        cout << s.geeksGcd(a, m) << endl;
        cout << "~" << endl;
    }
}
