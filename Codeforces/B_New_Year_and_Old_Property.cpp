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

// function for fast expo
ull fastexpo(ull a, ull b)
{
    if (b == 0)
    {
        return 1;
    }
    if (a == 0)
    {
        return 0;
    }
    ull y = fastexpo(a, b / 2);
    if (b % 2 == 0)
    {
        return y * y;
    }
    else
    {
        return a * y * y;
    }
}

set<ull> ss;
vector<ull> res;
void create(ull x)
{
    if (x > 1e18)
    {
        return;
    }
    ss.insert(x);
    // cout<<x<<ln;
    ull one = 1, two = 2;
    ull po = log2(x) + one;
    ull l = x + fastexpo(two, po);
    ull r = two * x + one;
    if (ss.count(l) == 0)
    {
        create(l);
    }
    if (ss.count(r) == 0)
    {
        create(r);
    }
}

void solve()
{
    ull n, m;
    cin >> n >> m;
    ll idx1 = lower_bound(all(res), n) - res.begin();
    ll idx2 = upper_bound(all(res), m) - res.begin() - 1;
    // cout << idx1 << " " << idx2 << ln;
    for (ll i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
        // string s = bitset<65>(res[i]).to_string();
        // reverse(all(s));
        // cout << s << " " << res[i] << ln;
    }
    // cout << ln;
    // cout << n << " " << m << ln;
    cout << idx2 - idx1 + 1 << ln;
}

// 11111101111111111111111111111111111111111111111111111111000000000
// 11111011111111111111111111111111111111111111111111111111000000000
// 11110111111111111111111111111111111111111111111111111111000000000
// 11101111111111111111111111111111111111111111111111111111000000000
// 11011111111111111111111111111111111111111111111111111111000000000
// 10111111111111111111111111111111111111111111111111111111000000000
// 01111111111111111111111111111111111111111111111111111111000000000

int main()
{
    fast_cin();
    ll t = 1;
    ss.insert(1);
    create(2);
    for (auto t : ss)
    {
        // cout << t << ln;
        res.pb(t);
    }
    sort(all(res));
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}