/*1 1 0
1 1 1
1 1 2
1 1 3
1 1 4
1 1 5
1 2 0
1 2 1
1 2 2
1 2 3
1 2 4
1 2 5
1 3 0
1 3 1
1 3 2
1 3 3
1 3 4
1 3 5
1 4 0
1 4 1
1 4 2
1 4 3
1 4 4
1 4 5
1 5 0
1 5 1
1 5 2
1 5 3
1 5 4
1 5 5
2 1 0
2 1 1
2 1 2
2 1 3
2 1 4
2 1 5
2 2 0
2 2 1
2 2 2
2 2 3
2 2 4
2 2 5
2 3 0
2 3 1
2 3 2
2 3 3
2 3 4
2 3 5
2 4 0
2 4 1
2 4 2
2 4 3
2 4 4
2 4 5
2 5 0
2 5 1
2 5 2
2 5 3
2 5 4
2 5 5
3 1 0
3 1 1
3 1 2
3 1 3
3 1 4
3 1 5
3 2 0
3 2 1
3 2 2
3 2 3
3 2 4
3 2 5
*/
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
    int r, b, d;
    cin >> r >> b >> d;
    if (r == 1 || b == 1)
    {
        if (abs(r - b) <= d)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return;
    }
    int res = max(r, b) % min(r, b);
    if (res == 0)
    {
        res = max(r, b) / min(r, b) - 1;
    }
    if (res <= d || r == b)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
