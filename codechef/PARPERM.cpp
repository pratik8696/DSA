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
#define max 100000
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
    ll n, k;
    cin >> n >> k;
    ll idx = lower_bound(all(prime), n) - prime.begin();
    // cout << prime[idx] << " " << idx << ln;
    map<int, vector<int>> m;
    m[1].pb(1);
    for (int i = 0; i <= idx; i++)
    {
        ll number = prime[i];
        for (int i = number; i <= n; i += number)
        {
            m[number].pb(i);
        }
    }
    set<int> other;
    vector<int> oprime;
    for (auto t : m)
    {
        // cout << t.first << " --> ";
        auto &v = t.second;
        if (v.size() == 1)
        {
            oprime.pb(t.first);
        }
        for (auto k : v)
        {
            if (v.size() > 1)
            {
                other.insert(k);
            }
            // cout << k << " ";
        }
        // cout << ln;
    }
    if (k <= oprime.size())
    {
        cout<<"YES"<<ln;
        for (int i = 0; i < k; i++)
        {
            cout << oprime[i] << " ";
        }
        cout << ln;
    }
    else if (k == other.size())
    {
        cout << "YES" << ln;
        for (auto t : other)
        {
            cout << t << " ";
        }
        cout << ln;
    }
    else
    {
        cout << "NO" << ln;
    }
}
int main()
{
    fast_cin();
    sieve();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}