#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef long long ll;
// use less_equal to make it multiset
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef unsigned long long ull;
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
typedef vector<pair<p64, ll>> vpp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef multiset<ll> ms64;
typedef multiset<p64> msp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef unordered_map<ll, v64> uv64;
typedef unordered_map<ll, ll> u64;
typedef unordered_map<p64, ll> up64;
typedef unordered_map<ll, vp64> uvp64;
typedef priority_queue<ll> pq64;
typedef priority_queue<ll, v64, greater<ll>> pqs64;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define ie insert
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

void create(vector<vector<char>> arr, string a, string b, ll x, ll y)
{
    string comp = '\/';
    if (a[0] == comp[1])
    {
        arr[x + 1][y] = '*';
        arr[x][y + 1] = '*';
    }
    else if (a[0] == comp[0])
    {
        arr[x][y] = '*';
        arr[x + 1][y + 1] = '*';
    }

    if (a[1] == comp[1])
    {
        arr[x + 1][y + 1] = '*';
        arr[x][y + 2] = '*';
    }
    else if (a[1] == comp[0])
    {
        arr[x + 1][y + 2] = '*';
        arr[x][y + 1] = '*';
    }

    // now in the lower half
    if (b[0] == comp[1])
    {
        arr[x + 1 + 2][y] = '*';
        arr[x + 2][y + 1] = '*';
    }
    else if (b[0] == comp[0])
    {
        arr[x + 2][y] = '*';
        arr[x + 1 + 2][y + 1] = '*';
    }

    if (b[1] == comp[1])
    {
        arr[x + 1 + 2][y + 1] = '*';
        arr[x + 2][y + 2] = '*';
    }
    else if (b[1] == comp[0])
    {
        arr[x + 1 + 2][y + 2] = '*';
        arr[x + 2][y + 1] = '*';
    }
}

class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
    {
        ll n = grid.size();
        vector<vector<char>> arr(20 * n +, vector<char>(20 * n, '.'));
        // if (// is \\) then just convert to single slash
        
    }
};
