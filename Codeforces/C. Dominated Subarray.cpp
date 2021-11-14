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
    int n;
    cin >> n;
    int arr[n];
    map<int, vector<int>> m;
    forn(i, n)
    {
        cin >> arr[i];
        m[arr[i]].pb(i);
    }
    int currmini = 0, minmini = INT_MAX;
    // for (auto &it : m)
    // {
    //     auto &array = it.second;
    //     if (array.size() >= 2)
    //     {
    //         for (int i = 0; i < array.size() - 1; i++)
    //         {
    //             currmini = abs(array[i + 1] - arr[i]);
    //             minmini = min(currmini, minmini);
    //         }
    //     }
    // }
    for (auto &it : m)
    {
        auto &a = it.first;
        auto &b = it.second;
        // cout << a << " --> ";
        if (b.size() >= 2)
        {
            for (int i = 0; i < b.size() - 1; i++)
            {
                currmini = abs(b[i] - b[i + 1]);
                minmini = min(currmini, minmini);
                // cout << b[i] << " ";
            }
            // cout << ln;
        }
    }
    if (minmini == INT_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << minmini + 1 << ln;
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