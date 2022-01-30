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

// function for sieve
#define max 100010
bool arr[max];
vector<ll> prime;
void sieve()
{
    ll i;
    fill(arr, arr + max, true);
    arr[0] = false;
    arr[1] = false;
    for (i = 0; i * i < max; i++)
    {
        if (arr[i] == true)
        {
            prime.pb(i);
            for (ll j = i * i; j < max; j += i)
            {
                arr[j] = false;
            }
        }
    }
    for (ll k = i; k < max; k++)
    {
        if (arr[k] == true)
        {
            prime.pb(k);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll arr[n][m];
    forn(i, n)
    {
        forn(j, m)
        {
            cin >> arr[i][j];
        }
    }
    ll minrow = INT_MAX, mincol = INT_MAX;
    forn(i, n)
    {
        ll rows = 0;
        forn(j, m)
        {
            ll idx = lower_bound(all(prime), arr[i][j]) - prime.begin();
            rows += prime[idx] - arr[i][j];
            // cout << prime[idx] << " ";
        }
        minrow = min(rows, minrow);
        // cout << ln;
    }

    // cout << ln;

    forn(j, m)
    {
        ll col = 0;
        forn(i, n)
        {
            ll idx = lower_bound(all(prime), arr[i][j]) - prime.begin();
            col += prime[idx] - arr[i][j];
            // cout << prime[idx] << " ";
        }
        mincol = min(col, mincol);
        // cout << ln;
    }
    cout << min(mincol, minrow) << ln;
}
int main()
{
    fast_cin();
    sieve();
    ll t = 1;
    //  cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}