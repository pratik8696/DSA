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
    ll n, m, i, j, k, x, y;
    string result;
    cin >> n >> m;
    while (n && m)
    {
        char c;
        if (m < n)
        {
            cout << "-1\n";
            return;
        }
        x = m % 10;
        y = n % 10;
        if (x >= y)
        {
            c = (x - y) + '0';
            result.pb(c);
            n /= 10;
            m /= 10;
        }
        else
        {
            x = m % 100;
            if (x - y > 9 || x - y < 0)
            {
                cout << "-1\n";
                return;
            }

            c = (x - y) + '0';
            result.pb(c);
            n /= 10;
            m /= 100;
        }
    }
    if (n)
    {
        cout << "-1\n";
        return;
    }
    while (m > 0)
    {
        k = m % 10;
        result.pb(k + '0');
        m /= 10;
    }
    reverse(result.begin(), result.end());
    i = 0;
    while (i < result.size() && result[i] == '0')
        i++;
    result = result.substr(i);
    cout << result << endl;
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