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
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(p64 x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ splitmix64(x.second + FIXED_RANDOM);
    }
    size_t operator()(ll x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef gp_hash_table<ll, ll, custom_hash> fm64;
typedef gp_hash_table<p64, ll, custom_hash> fmp64;

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

void bfs(uvp64 &adj, v64 &dist, ll src, v64 &parent, v64 &lvl)
{
    set<p64> q;
    q.ie({0, src});
    dist[src] = 0;
    lvl[src] = 0;
    parent[src] = src;
    while (!q.empty())
    {
        auto it = q.begin();
        ll curr = it->second;
        q.erase(it);
        for (auto t : adj[curr])
        {
            auto child = t.se;
            auto wt = t.fi;
            if (dist[child] > dist[curr] + wt)
            {
                q.erase({dist[child], child});
                dist[child] = dist[curr] + wt;
                q.ie({dist[child], child});
                parent[child] = curr;
                lvl[child] = lvl[curr] + 1;
            }
        }
    }
}

ll lca(ll a, ll b, v64 &lvl, v64 &dist, ll sparse[][30])
{
    ll oa, ob;
    oa = a, ob = b;
    ll rem = lvl[a] - lvl[b];
    if (rem < 0)
    {
        swap(a, b);
    }
    ll steps = abs(rem);
    while (steps)
    {
        // a needs to come up
        a = sparse[a][__lg(steps)];
        steps -= fastexpo(2, __lg(steps));
    }
    // cout << a << " " << b << ln;
    ll lca = 0;
    if (a == b)
    {
        lca = a;
    }
    else
    {
        for (ll i = 30 - 1; i >= 0; i--)
        {
            if (sparse[a][i] != sparse[b][i])
            {
                a = sparse[a][i];
                b = sparse[b][i];
            }
        }
        lca = sparse[a][0];
    }
    a = oa, b = ob;
    return dist[a] + dist[b] - 2 * dist[lca];
}

ll p, q, r;
ll node, diss = INF;
void dfs(int v, v64 &vis, uvp64 &adj, v64 &lvl, v64 &dist, ll sparse[][30])
{
    vis[v] = 1;
    ll curr_dis = lca(v, p, lvl, dist, sparse) + lca(v, q, lvl, dist, sparse) + lca(v, r, lvl, dist, sparse);
    if (curr_dis < diss)
    {
        diss = curr_dis;
        node = v;
    }
    for (auto t : adj[v])
    {
        auto child = t.se;
        if (vis[child] == 0)
        {
            dfs(child, vis, adj, lvl, dist, sparse);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    uvp64 adj;
    forn(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({c, b});
        adj[b].pb({c, a});
    }
    cin >> p >> q >> r;
    v64 par(n + 1, -1);
    v64 parent(n + 1, 0);
    ll sparse[n + 1][30];
    v64 lvl(n + 1, 0), dist(n + 1, INF);
    bfs(adj, dist, 1, parent, lvl);
    forsn(i, 1, n + 1)
    {
        sparse[i][0] = parent[i];
    }
    for (ll j = 1; j < 30; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
        }
    }
    v64 vis(n + 1, 0);
    dfs(1, vis, adj, lvl, dist, sparse);
    cout << node << ln;
}

int main()
{
    fast_cin();
    //#ifndef ONLINE_JUDGE
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    //#endif
    ll t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}

