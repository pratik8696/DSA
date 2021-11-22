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

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    ll sum = 0;
    for (ll i = 0; i <= n - 3; i++)
    {
        for (ll j = i + 2; j < n; j++)
        {
            ll i1 = i, j1 = j - 1, k1 = j, maxcurr = INT_MIN;
            if (abs(i - j) > 2)
            {
                k1 = i;
                i1 = j;
                for (int z = i; z <= j; z++)
                {
                    maxcurr = max((arr[i1] - arr[z]) * (arr[z] - arr[k1]), maxcurr);
                }
                sum += maxcurr;
            }
            else
            {
                sum += (arr[i1] - arr[j1]) * (arr[j1] - arr[k1]);
            }
            // cout<<sum<<ln;
            // cout << arr[i1] << " " << arr[j1] << " " << arr[k1] << ln;
        }
    }
    cout << sum << ln;
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