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

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    map<ll, ll> m;
    forn(i, n)
    {
        cin >> arr[i];
        m[arr[i]]++;
    }
    if (m[2] > 0)
    {
        m[2]--;
        cout << 2 << " ";
        if (m[1] > 0)
        {
            m[1]--;
            cout << 1 << " ";
            ll rep = m[2];
            ll val = 2;
            while (rep--)
            {
                cout << val << " ";
            }
            ll reps = m[1];
            ll vals = 1;
            while (reps--)
            {
                cout << vals << " ";
            }
        }
        else
        {
            ll rep = m[2];
            while (rep--)
            {
                cout << 2 << " ";
            }
            cout << ln;
        }
    }
    else
    {
        forn(i, n)
        {
            cout << arr[i] << " ";
        }
        cout << ln;
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