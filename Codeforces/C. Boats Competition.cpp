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
    vector<pair<int, int>> arr;
    forn(i, n)
    {
        int x;
        cin >> x;
        arr.pb(mp(x, 0));
    }
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                m[arr[i].first + arr[j].first]++;
            }
        }
    }
    int maxi = INT_MIN, maxpair = INT16_MIN;
    for (auto t : m)
    {
        // cout << t.fi << " " << t.se << endl;
        if (t.se > maxi)
        {
            maxi = t.se;
            maxpair = t.fi;
        }
    }
    // cout << maxpair << " " << maxi << ln;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i].first + arr[j].first) == maxpair)
            {
                if (i != j && arr[i].second == 0 && arr[j].second == 0)
                {
                    arr[i].second = 1;
                    arr[j].second = 1;
                    count++;
                }
            }
        }
    }
    cout<<count<<ln;
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
















































































// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 2
// 1 1
// 2
// 2 1
// 2
// 1 1
// 2
// 2 2
// 2
// 2 2
// 2
// 2 2
// 3
// 2 1 1
// 3
// 2 1 1
// 3
// 2 2 1
// 3
// 1 2 1
// 3
// 3 3 3
// 3
// 3 2 3
// 4
// 2 2 1 1
// 4
// 1 2 3 2
// 4
// 4 2 4 3
// 4
// 4 3 3 3
// 4
// 4 4 4 4
// 4
// 4 4 4 4
// 5
// 1 1 1 1 1
// 5
// 1 1 1 1 1
// 5
// 1 4 3 5 5
// 5
// 2 5 2 1 1
// 5
// 5 4 4 5 5
// 5
// 4 4 5 5 5
// 6
// 2 2 1 1 1 1
// 6
// 2 1 1 1 2 1
// 6
// 5 1 6 4 2 3
// 6
// 3 3 1 2 4 4
// 6
// 6 5 6 6 5 6
// 6
// 6 6 6 6 6 6
// 7
// 1 1 1 2 1 2 1
// 7
// 2 1 3 1 3 1 1
// 7
// 3 7 1 3 7 2 1
// 7
// 4 4 5 4 2 4 6
// 7
// 6 7 7 5 7 7 7
// 7
// 6 5 6 7 6 7 6