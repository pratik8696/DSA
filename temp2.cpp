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

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    return true;
}

ll fun(ll i, ll j, vv64 &arr, vv64 &dp)
{
    if (i == n)
    {
        return arr[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    ll left = -INF, right = -INF, down = -INF;
    ll maxx = -INF;
    if (isvalid(i + 1, j))
    {
        maxx = max(fun(i + 1, j, arr, dp), maxx);
    }
    if (isvalid(i + 1, j - 1))
    {
        maxx = max(fun(i + 1, j - 1, arr, dp), maxx);
    }
    if (isvalid(i + 1, j + 1))
    {
        maxx = max(fun(i + 1, j + 1, arr, dp), maxx);
    }
    return dp[i][j] = arr[i][j] + maxx;
}

void solve()
{
    cin >> n >> m;
    vv64 arr(n + 10, v64(m + 10, 0)), dp(n + 10, v64(m + 10, INF));
    forsn(i, 1, n + 1)
    {
        forsn(j, 1, m + 1)
        {
            cin >> arr[i][j];
        }
    }
    ll ans = -INF;
    // forsn(i, 1, m + 1)
    // {
    //     ans = max(ans, fun(1, i, arr, dp));
    // }

    // cout << ans << ln;

    // base case
    forsn(i, 1, m + 1)
    {
        dp[n][i] = arr[n][i];
    }
    for (ll i = n - 1; i >= 1; i--)
    {
        for (ll j = m; j >= 1; j--)
        {
            ll left = -INF, right = -INF, down = -INF;
            ll maxx = -INF;
            if (isvalid(i + 1, j))
            {
                maxx = max(dp[i + 1][j], maxx);
            }
            if (isvalid(i + 1, j - 1))
            {
                maxx = max(dp[i + 1][j - 1], maxx);
            }
            if (isvalid(i + 1, j + 1))
            {
                maxx = max(dp[i + 1][j + 1], maxx);
            }
            dp[i][j] = arr[i][j] + maxx;
        }
    }

    forsn(j, 1, m + 1)
    {
        ans = max(dp[1][j], ans);
    }

    cout << ans << ln;
}

int main()
{
    // fast_cin();
    //#ifndef ONLINE_JUDGE
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    //#endif
    ll t = 1;
    cin >> t;
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
