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
#define maxi 100000
vector<int> arr[maxi];
int vis[maxi];
vector<int> path;
int cc;
void dfs(int v)
{
    vis[v] = 1;
    path.pb(v);
    for (auto child : arr[v])
    {
        if (vis[child] == 0)
        {
            dfs(child);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    forn(i, n - 1)
    {
        arr[i + 1].pb(i + 2);
    }
    int ar[n];
    forn(i, n)
    {
        cin >> ar[i];
        if (ar[i] == 0)
        {
            arr[i + 1].pb(n + 1);
        }
        else
        {
            arr[n + 1].pb(i + 1);
        }
    }
    // for (int i = 1; i <= n + 1; i++)
    // {
    //     cout << i << "-->";
    //     for (auto t : arr[i])
    //     {
    //         cout << t << " ";
    //     }
    //     cout << ln;
    // }
    if (arr[1].size() >= 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
                cc++;
            }
        }
    }
    else
    {
        for (int i = n + 1; i >= 1; i--)
        {
            if (vis[i] == 0)
            {
                dfs(i);
                cc++;
            }
        }
    }
    if (cc != 1)
    {
        cout << -1 << ln;
    }
    else
    {
        for (auto t : path)
        {
            cout << t << " ";
        }
        cout << ln;
    }
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        for (int i = 0; i < maxi; i++)
        {
            arr[i].clear();
        }
        fill(al(vis, maxi), 0);
        path.clear();
        cc = 0;
        solve();
    }
    return 0;
}