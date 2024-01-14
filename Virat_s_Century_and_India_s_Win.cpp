#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

#define ln "\n"
#define mp make_pair
#define ie insert
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())
#define dbg(a) cout << a << endl;
#define dbg2(a) cout << a << ' ';
using ld = long double;
using db = double;

// modular exponentiation
long long modpow(long long x, long long n, long long p)
{

    if (n == 0)
        return 1 % p;

    ll ans = 1, base = x;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = (ans * base) % p;
            n--;
        }
        else
        {
            base = (base * base) % p;
            n /= 2;
        }
    }
    if (ans < 0)
        ans = (ans + p) % p;
    return ans;
}

ll n, b, w, x;
int denom = modpow(6, MOD - 2, MOD);
int dp[61][101][151][2][11][2];
ll sum(ll ball_left, ll virat, ll score, ll strike, ll wickets, ll out)
{
    if (wickets == 10)
    {
        return 0;
    }
    if (virat == 100 && score == 0)
    {
        return 1;
    }
    if (score == 0)
    {
        return 0;
    }
    if (ball_left == 0)
    {
        return 0;
    }
    auto &x = dp[ball_left][virat][score][strike][wickets][out];
    if (x != -1)
    {
        ll value = x;
        return value;
    }
    ll ans = 0;
    // consider all probability also consider over end
    if (strike && out == 0)
    {
        ans += (sum(ball_left - 1, virat, score, strike, wickets + 1, 1) * denom) % MOD;
        ans %= MOD;
        ans += (sum(ball_left - 1, min(virat + 1, 100ll), max(score - 1, 0ll), ((ball_left - 1) % 6 == 0 ? 1 : 0), wickets, out) * denom) % MOD; // over wla case ayega
        ans %= MOD;
        ans += (sum(ball_left - 1, min(virat + 3, 100ll), max(score - 3, 0ll), ((ball_left - 1) % 6 == 0 ? 1 : 0), wickets, out) * denom) % MOD; // over wla case ayega
        ans %= MOD;
        ans += (sum(ball_left - 1, min(virat + 2, 100ll), max(score - 2, 0ll), ((ball_left - 1) % 6 == 0 ? 0 : 1), wickets, out) * denom) % MOD; // over wla case ayega
        ans %= MOD;
        ans += (sum(ball_left - 1, min(virat + 4, 100ll), max(score - 4, 0ll), ((ball_left - 1) % 6 == 0 ? 0 : 1), wickets, out) * denom) % MOD; // over wla case ayega
        ans %= MOD;
        ans += (sum(ball_left - 1, min(virat + 6, 100ll), max(score - 6, 0ll), ((ball_left - 1) % 6 == 0 ? 0 : 1), wickets, out) * denom) % MOD; // over wla case ayega}
        ans %= MOD;
    }
    else
    {
        ans += (sum(ball_left - 1, virat, score, ((ball_left - 1) % 6 == 0 ? 1 : 0), wickets + 1, out) * denom) % MOD;
        ans %= MOD;
        ans += (sum(ball_left - 1, virat, max(score - 1, 0ll), ((ball_left - 1) % 6 == 0 ? 0 : 1), wickets, out) * denom) % MOD; // over wla case ayega
        ans %= MOD;
        ans += (sum(ball_left - 1, virat, max(score - 3, 0ll), ((ball_left - 1) % 6 == 0 ? 0 : 1), wickets, out) * denom) % MOD; // over wla case ayega
        ans %= MOD;
        ans += (sum(ball_left - 1, virat, max(score - 2, 0ll), ((ball_left - 1) % 6 == 0 ? 1 : 0), wickets, out) * denom) % MOD; // over wla case ayega
        ans %= MOD;
        ans += (sum(ball_left - 1, virat, max(score - 4, 0ll), ((ball_left - 1) % 6 == 0 ? 1 : 0), wickets, out) * denom) % MOD; // over wla case ayega
        ans %= MOD;
        ans += (sum(ball_left - 1, virat, max(score - 6, 0ll), ((ball_left - 1) % 6 == 0 ? 1 : 0), wickets, out) * denom) % MOD; // over wla case ayega}
        ans %= MOD;
    }
    return x = ans % MOD;
}

void solve()
{
    cin >> n >> b >> w >> x;
    int ans = sum(b, x, n, 1, w, 0);
    cout << int(ans) << endl;
}

int main()
{
    fast_cin();
    memset(dp, -1, sizeof(dp));
    ll t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
