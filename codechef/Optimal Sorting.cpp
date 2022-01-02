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

vector<ll> arr[100000];

void solve()
{
    ll n;
    cin >> n;
    ll j;
    pair<ll, ll> a[n];
    ll duplicate[n];
    for (j = 0; j < 100000; j++)
        arr[j].clear();
    for (j = 0; j < n; j++)
    {
        cin >> a[j].first;
        duplicate[j] = a[j].first;
        a[j].second = j;
    }
    sort(a, a + n);
    vector<pair<ll, ll>> temporary;
    for (j = 0; j < n; j++)
    {
        if (a[j].first != j)
        {
            if (j < a[j].second)
            {
                temporary.pb({j, a[j].second});
            }
            else
            {
                temporary.pb({a[j].second, j});
            }
        }
    }
    sort(all(temporary));
    vector<pair<ll, ll>> ok;
    ll st = -1, en = -1;
    for (j = 0; j < temporary.size(); j++)
    {
        if (st == -1)
        {
            st = temporary[j].first;
            en = temporary[j].second;
        }
        else if (temporary[j].first > en)
        {
            ok.push_back({st, en});
            st = temporary[j].first;
            en = temporary[j].second;
        }
        else
        {
            en = max(temporary[j].second, en);
        }
    }
    if (st != -1)
        ok.push_back({st, en});
    ll finalresult = 0;
    for (j = 0; j < ok.size(); j++)
    {
        ll mn = INT_MAX, mx = -1000000008;
        for (ll k = ok[j].first; k <= ok[j].second; k++)
        {
            mn = min(duplicate[k], mn);
            mx = max(duplicate[k], mx);
        }
        finalresult += abs(mx - mn);
    }
    cout << finalresult << "\n";
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