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
const int MOD = 1000000007;
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
#define dbg(a) cout << a << endl;
#define dbg2(a) cout << a << ' ';
using ld = long double;
using db = double;
using str = string; // yay python!
// INPUT
#define tcT template <class T
#define tcTU tcT, class U
#define tcTUU tcT, class... U
tcT > void re(T &x)
{
    cin >> x;
}
tcTUU > void re(T &t, U &...u)
{
    re(t);
    re(u...);
}

u64 val;
ll final_ans = 0;
v64 dfs(int v, v64 &vis, uv64 &adj)
{
    vis[v] = 1;
    v64 node(4);
    for (auto child : adj[v])
    {
        if (vis[child] == 0)
        {
            v64 curr = dfs(child, vis, adj);
            forn(i, 4)
            {
                node[i] += curr[i];
            }
        }
    }
    ll ee = 0, eo = 0, oe = 0, oo = 0;
    if (v % 2 == 0 && val[v] % 2 == 0)
    {
        ee++;
    }
    if (v % 2 == 0 && val[v] % 2 != 0)
    {
        eo++;
    }
    if (v % 2 != 0 && val[v] % 2 == 0)
    {
        oe++;
    }
    if (v % 2 != 0 && val[v] % 2 != 0)
    {
        oo++;
    }
    node[0] += ee;
    node[1] += eo;
    node[2] += oe;
    node[3] += oo;
    ll curr = 0;
    curr += max(0ll, (node[0] * (node[0] - 1)) / 2);
    curr += max(0ll, (node[1] * (node[1] - 1)) / 2);
    curr += max(0ll, (node[2] * (node[2] - 1)) / 2);
    curr += max(0ll, (node[3] * (node[3] - 1)) / 2);
    curr += node[0] * node[3];
    curr += node[1] * node[2];
    if (curr % 2 == 0 && curr)
    {
        final_ans++;
    }
    return node;
}

void solve()
{
    ll n;
    cin >> n;
    uv64 adj;
    forn(i, n - 1)
    {
        ll x;
        cin >> x;
        adj[x].pb(i + 2);
        adj[i + 2].pb(x);
    }
    forn(i, n)
    {
        ll x;
        cin >> x;
        val[i + 1] = x;
    }
    v64 vis(n + 1, 0);
    v64 value(4);
    v64 v = dfs(1, vis, adj);
    dbg(final_ans);
}

int main()
{
    fast_cin();
    ll t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}

