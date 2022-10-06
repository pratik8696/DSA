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
typedef long long ll;
typedef unsigned long long int ull;
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
#define forn(i, n) for (ll i = 0; i < n; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define alll(arr, n) (arr), (arr) + (n)
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



// function for segmented sieve
void segmentedsieve(ll m, ll n)
{
    bool segment[n - m + 1];
    fill(segment, segment + n - m + 1, true);
    for (int i = 0; prime[i] * prime[i] < n; i++)
    {
        int start;
        if (prime[i] >= m && prime[i] <= n)
        {
            start = prime[i] * 2;
        }
        else
        {
            start = (m / prime[i]) * prime[i];
            if (start < m)
            {
                start += prime[i];
            }
        }
        for (int j = start; j <= n; j += prime[i])
        {
            segment[j - m] = false;
        }
    }
    for (int i = m; i <= n; i++)
    {
        if (segment[i - m] == true && i != 1 && i != 0)
        {
            cout << i;
        }
    }
    cout << ln;
} // here is the output

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

// function for modularexpo
ll modexpo(long long a, long long n, long long p)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % p;
            n--;
        }
        else
        {
            a = (a * a) % p;
            n /= 2;
        }
    }
    return res;
}

// function for extended euclid
ll x, y, gcd;
void extendedeuclid(ll a, ll b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        gcd = a;
        return;
    }
    extendedeuclid(b, a % b);
    ll cx = y;
    ll cy = x - (a / b) * y;
    x = cx;
    y = cy;
}

// function for multiplicative modular inverse
ll modularmulinv(ll a, ll m)
{
    extendedeuclid(a, m);
    return (x + m) % m;
}

// function for advanced gcd
ll advancedgcd(ll a, string s)
{
    ll res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        res = (res * 10 + s[i] - '0') % a;
    }
    return __gcd(a, res);
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

// check for integer
bool isint(double n)
{
    if (float(n) == ceil(n))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    forn(i, n)
    {
        cin >> arr[i];
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