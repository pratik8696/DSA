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
    int n;
    cin >> n;
    map<int, int> m;
    // map can basically hash any values for u
    // inserting 10 integers in the map
    // here it may seem like it works similar to array
    forn(i, n)
    {
        int t;
        cin >> t;
        m[i] = t;
    }
    for (auto k : m)
    {
        cout << k.first << " " << k.second << endl;
    }
    // now we will try out the find and erase function also the count function
    int u;
    cin >> u;
    if (m.count(u))
    {
        cout << "The element is " << m[u] << endl;
    }
    else
    {
        cout << "The element does not exist in the map" << endl;
    }
    // now erasing the element in the map
    int e;
    cin >> e;
    if (m.count(e))
    {
        m.erase(e);
        cout << "Element has been deleted successfully" << endl;
    }
    else
    {
        cout << "Element does not exist" << endl;
    }
    for (auto k : m)
    {
        cout << k.first << " " << k.second << endl;
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