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
set<ll> bucket;
vector<ll> sortbucket;

void cr(ll s)
{
    // cout<<s<<ln;
    bucket.insert(s);
    if (s > 9999999999)
    {
        return;
    }
    set<char> b;
    string ss = to_string(s);
    int k = 0;
    forn(i, ss.length())
    {
        b.insert(ss[i]);
    }
    char first, second;
    for (auto t : b)
    {
        if (k == 0)
        {
            first = t;
            k = 1;
        }
        else
        {
            second = t;
        }
    }
    ll t = s, p = s;
    t = t * 10 + first - '0';
    p = p * 10 + second - '0';
    cr(t);
    if (b.size() == 1)
    {
        for (int i = 0; i <= 9; i++)
        {
            ll k = s;
            k = k * 10 + i;
            cr(k);
        }
    }
    else
    {
        cr(p);
    }
}

void solve()
{
    int n;
    cin >> n;
    // cout << sortbucket.size() << ln;
    ll idx = upper_bound(all(sortbucket), (n)) - sortbucket.begin();
    cout << idx << ln;
}
int main()
{
    fast_cin();
    ll t = 1;
    for (int i = 1; i <= 9; i++)
    {
        cr(i);
    }
    for (int i = 10; i <= 100; i++)
    {
        string s = to_string(i);
        set<char> t;
        forn(i, s.length())
        {
            t.insert(s[i]);
        }
        if (t.size() == 2)
        {
            cr(i);
        }
    }
    for (auto t : bucket)
    {
        sortbucket.pb((t));
    }
    sort(all(sortbucket));
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}