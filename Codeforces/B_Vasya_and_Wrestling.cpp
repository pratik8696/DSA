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
    vector<int> first, second;
    ll f = 0, s = 0;
    forn(i, n)
    {
        cin >> arr[i];
        if (arr[i] >= 0)
        {
            first.pb(arr[i]);
            f += arr[i];
        }
        else
        {
            second.pb(abs(arr[i]));
            s += abs(arr[i]);
        }
    }
    if (f > s)
    {
        cout << "first" << ln;
        return;
    }
    else if (f < s)
    {
        cout << "second" << ln;
        return;
    }
    else
    {
        if (f == s)
        {
            ll mini = min(first.size(), second.size());
            for (int i = 0; i < mini; i++)
            {
                if (first[i] > second[i])
                {
                    cout << "first" << ln;
                    return;
                }
                else if (second[i] > first[i])
                {
                    cout << "second" << ln;
                    return;
                }
            }
        }
        if (arr[n - 1] < 0)
        {
            cout << "second" << ln;
            return;
        }
        else
        {
            cout << "first" << ln;
            return;
        }
    }
}
int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}