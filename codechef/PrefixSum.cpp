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

// ll popcount(ll n)
//{
// ll c = 0;
// for (; n; ++c)
// n &= n - 1;
// return c;
// }
// 10
// 1 2 3 4  5  6  7  8  9  10
// 0 1 3 6 10 15 21 28 36 45 55
// 0 1 2 3  4 5  6   7  8  9 10
// 5
// l r
// arr[r]-arr[l-1]
// 1 6
// 8 10
// 3 10
// 1 2 3 4 5  6 7
// 0 0 0 0 0  0 
// 100 2 0 0 -9 0 -101
// 100 102 102 102 93 93 0
// 0  0  0  0  0 
// -8 0  0  0  +8
// -8 -8 -8 -8 0
// 1
// 1 4 -8
// 2 4 2
// 5 6 1
// 1 6 100
// 5
// 1 6
// 8 10
// 3 10

// 9 2 4 5 7 8  1  10
// 0 0 0 0 0 0  0  0 
// 1 1 1 2 -1 -2 -1 -1
// 1 2 3 5  4  2  1  0


// 6
// 1 7
// 2 5
// 3 6
// 4 5
// 4 4

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    v64 res;
    res.pb(0);
    ll sum = 0;
    forn(i, n)
    {
        sum += arr[i];
        res.pb(sum);
    }
    int q;
    cin >> q;
    forn(i, q)
    {
        ll l, r;
        cin >> l >> r;
        cout << res[r] - res[l - 1] << ln;
    }
}
int main()
{
    fast_cin();
    ll t = 1;
    //  cin >> t;
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
