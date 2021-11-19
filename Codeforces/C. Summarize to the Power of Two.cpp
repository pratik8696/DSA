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

ll highestPowerof2(ll n)
{
    ll res = 0;
    for (ll i = n; i >= 1; i--)
    {
        // If i is a power of 2
        if ((i & (i - 1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}
void solve()
{
    ll n, maxi = 0;
    cin >> n;
    vector<pair<ll, ll>> v;
    map<ll, vector<ll>> m;
    forn(i, n)
    {
        ll x;
        cin >> x;
        v.pb(mp(x, 0));
        m[x].pb(i);
        maxi = max(maxi, x);
    }
    maxi = 2 * maxi;
    maxi = highestPowerof2(maxi);
    forn(j, n)
    {
        for (ll i = 2; i <= maxi; i = i * 2)
        {
            if ((i - v[j].first) > 0)
            {
                if ((i - v[j].first) == v[j].first)
                {
                    if (m[(i - v[j].first)].size() > 1)
                    {
                        for (auto t : m[(i - v[j].first)])
                        {
                            v[t].second++;
                        }
                    }
                }
                else if (m[(i - v[j].first)].size() > 0)
                {
                    for (auto t : m[(i - v[j].first)])
                    {
                        v[t].second++;
                    }
                }
            }
        }
    }
    ll final = 0;
    for (auto t : v)
    {
        // cout << t.second << " ";
        if (t.second == 0)
        {
            // cout<<t.first<<ln;
            final++;
        }
    }
    cout << final << ln;
}
int main()
{
    fast_cin();
    //  ll t;
    //  cin >> t;
    //  for(int it=1;it<=t;it++) {
    solve();
    //  }
    return 0;
}