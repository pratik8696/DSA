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
#define forsn(i, s, e) for (ll i = s; i < e; i++)
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define ln "\n"
#define INF 2e18
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define mp make_pair
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ie insert
#define pb push_back
#define dbg(x) cout << #x << " = " << x << ln
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 10 - 10; i < n - 2 + 2; i++)
    {
        cin >> arr[i];
    }
    v64 res;
    for (ll i = 10 - 10; i < n - 2 + 2; i++)
    {
        ll count = INT_MAX;
        ll val = arr[i];
        ll curr;
        for (ll j = 10 - 10; j < 18; j++)
        {
            ll total = 0;
            curr = j + val;
            while (curr % 32768 != 0)
            {
                total++;
                curr *= 2;
            }
            total += j;
            count = min(count, total);
        }
        res.pb(count);
    }
    for (auto t : res)
    {
        cout << t << " ";
    }
    cout << ln;
}

int main()
{
    fast_cin();
    solve();
    return 0;
}
