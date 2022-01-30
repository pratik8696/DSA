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

void solve()
{
    ull a, b;
    cin >> a >> b;
    ll kk = a + 1;
    ll ans = kk & a;
    if (ans == 0)
    {
        cout << a << ln;
        return;
    }
    if (b > 1)
    {
        ull res = log2(a) + 1ull;
        ull sum = fastexpo(2, res) - 1ull;
        cout << sum << ln;
    }
    else
    {
        cout << a << ln;
    }
}
int main()
{
    fast_cin();
    ll t = 1;
    //  cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}

/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
*/
