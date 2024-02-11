#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to calculate x raised to the power n modulo M.
    using ll = unsigned long long int;
    ll powm(ll x, ll n, ll M)
    {
        // Initializing result to 1.
        ll result = 1;
        while (n > 0)
        {
            // If n is odd, multiply result with x and take modulo M.
            if (n % 2 == 1)
                result = (result * x) % M;
            // Square x and take modulo M.
            x = (x * x) % M;
            // Divide n by 2.
            n = n / 2;
        }
        // Returning result.
        return result;
    }
    // Function to find the nth term of an arithmetic series.
    int Nth_term(int a, int r, int n)
    {
        // Modulo variable.
        ll mod = 1e9 + 7;
        // Calculating the power of r raised to the (n-1)th power modulo mod.
        ll res = powm(r, n - 1, mod);
        // Multiplying the result with a and taking modulo mod.
        res *= a;
        res %= mod;
        // Returning the result when converted to int.
        return int(res);
    }
};

int main()
{
    freopen("1input.txt", "r", stdin);
    freopen("1output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, r, n;
        cin >> a >> r >> n;
        Solution ob;
        char x;
        cin >> x;
        int ans = ob.Nth_term(a, r, n);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}