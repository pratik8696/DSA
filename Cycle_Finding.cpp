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

void dfs(int v, v64 &vis, uv64 &adj)
{
    vis[v] = 1;
    for (auto child : adj[v])
    {
        if (vis[child] == 0)
        {
            dfs(child, vis, adj);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vv64 edges;
    v64 vis(n + 1, 0);
    uv64 adj;
    forn(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.pb({a, b, c});
        adj[a].pb(b);
    }
    v64 dist(n + 1, INF);
    v64 parent(n + 1, 0);
    forsn(i, 1, n + 1)
    {
        if (vis[i] == 0)
        {
            dfs(i, vis, adj);
            dist[i] = 0;
            parent[i] = i;
        }
    }
    ll flag = 1, last;
    forn(z, n - 1)
    {
        bool any = 0;
        forn(i, m)
        {
            ll u = edges[i][0];
            ll v = edges[i][1];
            ll wt = edges[i][2];
            if (dist[u] + wt < dist[v] && dist[u] != INF)
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;
                any = 1;
            }
        }
        if (!any)
        {
            break;
        }
    }
    forn(i, m)
    {
        ll u = edges[i][0];
        ll v = edges[i][1];
        ll wt = edges[i][2];
        if (dist[u] + wt < dist[v] && dist[u] != INF)
        {
            dist[v] = dist[u] + wt;
            parent[v] = u;
            flag = 0;
            last = v;
        }
    }
    if (flag == 0)
    {
        cout << "YES" << ln;
        ll prev = last;
        deque<ll> path;
        s64 cc;
        while (cc.count(prev) == 0)
        {
            cc.ie(prev);
            path.pb(prev);
            prev = parent[prev];
        }
        path.pb(prev);
        last = prev;
        forn(i, path.size())
        {
            if (path[0] != last)
            {
                path.pop_front();
            }
            else
            {
                break;
            }
        }
        reverse(all(path));
        for (auto t : path)
        {
            cout << t << " ";
        }
        cout << ln;
    }
    else
    {
        cout << "NO" << ln;
    }
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

/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
*/
