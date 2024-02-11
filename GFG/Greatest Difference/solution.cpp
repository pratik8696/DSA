#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long geekLovesChocolate(int N)
    {
        const int MOD = 1e9 + 7;
        long long n = N;
        long long ans = ((((n * (n + 1)) % MOD) * (4 * n - 1)) % MOD) % MOD;
        return ans % MOD;
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
        Solution obj;
        long long res = obj.geekLovesChocolate(N);
        char x;
        cin >> x;
        cout << res << endl;
        cout << "~" << endl;
    }
}
