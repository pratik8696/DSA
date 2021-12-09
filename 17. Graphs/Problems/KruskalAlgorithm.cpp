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
#define maxi 100001
#define arsize 10001

struct edge
{
    int a;
    int b;
    int w;
};

edge arr[maxi];
int par[arsize];

void merge(int a, int b)
{
    par[a] = b;
}

int find(int a)
{
    if (par[a] == -1)
    {
        return a;
    }
    return par[a]=find(par[a]);
}

bool compare(edge a, edge b)
{
    return a.w < b.w;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        par[i] = -1;
    }
    ll sum = 0;
    forn(i, m)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }
    sort(al(arr, m), compare);
    for (int i = 0; i < m; i++)
    {
        int a = find(arr[i].a);
        int b = find(arr[i].b);
        if (a != b)
        {
            sum += arr[i].w;
            merge(a, b);
        }
    }
    cout << sum << ln;
}

int main()
{
    fast_cin();
    // ll t;
    // cin >> t;
    // for (int it = 1; it <= t; it++)
    // {
    solve();
    // }
    return 0;
}