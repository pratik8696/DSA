#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
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

// function for prime factorization
vector<pair<ll, ll>> pf(ll n)
{
    vector<pair<ll, ll>> prime;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n = n / i;
            }
            prime.pb(mp(i, count));
        }
    }
    if (n > 1)
    {
        prime.pb(mp(n, 1));
    }
    return prime;
}

// sum of digits of a number
ll sumofno(ll n)
{
    ll sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

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

// const int N = 1e6 + 100;
// long long fact[N];
//  initialise the factorial
// void initfact(){
// fact[0] = 1;
// for (int i = 1; i < N; i++)
//{
// fact[i] = (fact[i - 1] * i);
// fact[i] %= MOD;
// }}

// formula for c
// ll C(ll n, ll i)
//{
// ll res = fact[n];
// ll div = fact[n - i] * fact[i];
// div %= MOD;
// div = modpow(div, MOD - 2, MOD);
// return (res * div) % MOD;
// }

long long CW(ll n, ll m)
{
    if (m > n - m)
        m = n - m;
    long long ans = 1;
    for (int i = 0; i < m; i++)
    {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

// function for fast expo
ll fastexpo(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (a == 0)
    {
        return 0;
    }
    ll y = fastexpo(a, b / 2);
    if (b % 2 == 0)
    {
        return y * y;
    }
    else
    {
        return a * y * y;
    }
}

ll popcount(ll n)
{
    ll c = 0;
    for (; n; ++c)
        n &= n - 1;
    return c;
}

ll ce(ll x, ll y)
{
    ll res = x / y;
    if (x % y != 0)
    {
        res++;
    }
    return res;
}

bool pow2(ll x)
{
    ll res = x & (x - 1);
    if (res == 0)
    {
        return true;
    }
    return false;
}

bool isPrime(int x)
{
    for (int d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n / 2], b[n / 2];
    forn(i, n / 2)
    {
        a[i] = i;
    }
    ll org = n - 1;
    forn(i, n / 2)
    {
        b[i] = org--;
    }
    if (k > n - 1)
    {
        cout << -1 << ln;
        return;
    }
    if (n == 4 && k == 3)
    {
        cout << -1 << ln;
        return;
    }
    if (k == 0)
    {
        vp64 ans;
        forn(i, n / 2)
        {
            cout << a[i] << " " << b[i] << ln;
        }
        return;
    }
    else if (k == n - 1)
    {
        vp64 ans;
        // ab 2^n wla sab lena hai
        v64 powers, compliment;
        forn(i, n / 2)
        {
            ll val = a[i] & (a[i] - 1);
            if (val == 0 && i != 0)
            {
                powers.pb(i);
                compliment.pb(b[i]);
                a[i] = INT_MAX;
                b[i] = INT_MAX;
            }
        }
        powers.pb(n / 2);
        compliment.pb(n / 2 - 1);
        a[n / 2 - 1] = INT_MAX;
        b[n / 2 - 1] = INT_MAX;
        rotate(powers.begin(), powers.begin() + 1, powers.end());
        forn(i, powers.size())
        {
            ans.pb({powers[i], compliment[i]});
        }
        forn(i, n / 2)
        {
            if (a[i] != INT_MAX)
            {
                ans.pb({a[i], b[i]});
            }
        }
        for (auto t : ans)
        {
            cout << t.fi << " " << t.se << ln;
        }
        return;
    }
    else
    {
        vp64 ans;
        // ek to n-1 hoga and dusra k
        for (ll i = 0; i < n / 2; i++)
        {
            if (a[i] == k)
            {
                ans.pb({n - 1, k});
                ans.pb({0, b[i]});
                a[i] = INT_MAX;
                b[i] = INT_MAX;
                a[0] = INT_MAX;
                b[0] = INT_MAX;
                break;
            }
            else if (b[i] == k)
            {
                ans.pb({n - 1, k});
                ans.pb({0, a[i]});
                a[i] = INT_MAX;
                b[i] = INT_MAX;
                a[0] = INT_MAX;
                b[0] = INT_MAX;
                break;
            }
        }
        forn(i, n / 2)
        {
            if (a[i] != INT_MAX)
            {
                ans.pb({a[i], b[i]});
            }
        }
        for (auto t : ans)
        {
            cout << t.fi << " " << t.se << ln;
        }
        return;
    }
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}

/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
*/
