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
typedef long long ll;
using namespace __gnu_pbds;
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

ll n, m, timer;
fmp64 edges;
v64 path;
u64 val;

void dfs_bridges(int v, int p, v64 &visited, v64 &low, v64 &tin, uv64 &adj)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs_bridges(to, v, visited, low, tin, adj);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                edges[{v, to}] = 1;
                edges[{to, v}] = 1;
            }
        }
    }
}

void find_bridges(v64 &visited, v64 &low, v64 &tin, uv64 &adj)
{
    timer = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs_bridges(i, -1, visited, low, tin, adj);
        }
    }
}

void dfs_val(int v, v64 &vis, uv64 &adj)
{
    vis[v] = 1;
    path.pb(v);
    for (auto child : adj[v])
    {
        ll check = edges[{v, child}];
        if (vis[child] == 0 && check == 0)
        {
            dfs_val(child, vis, adj);
        }
    }
}

ll ans = 0;
void dfs(int v, v64 &vis, uv64 &adj)
{
    vis[v] = 1;
    for (auto child : adj[v])
    {
        if (edges[{child, v}])
        {
            ans += val[child] * val[v];
        }
        if (vis[child] == 0)
        {
            dfs(child, vis, adj);
        }
    }
}

void solve()
{
    cin >> n >> m;
    uv64 adj;
    
    forn(i, m)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    v64 visited(n + 1, 0);
    v64 tin(n + 1, -1), low(n + 1, -1);
    find_bridges(visited, low, tin, adj);
    fill(all(visited), 0);
    forsn(i, 1, n + 1)
    {
        if (visited[i] == 0)
        {
            dfs_val(i, visited, adj);
            for (auto t : path)
            {
                val[t] = path.size();
            }
            path.clear();
        }
    }
    fill(all(visited), 0);
    forsn(i, 1, n + 1)
    {
        if (visited[i] == 0)
        {
            dfs(i, visited, adj);
        }
    }
    cout << (ans / 2) << ln;
    ans = 0, timer = 0;
    edges.clear();
    path.clear();
    val.clear();
}

int main()
{
    fast_cin();
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