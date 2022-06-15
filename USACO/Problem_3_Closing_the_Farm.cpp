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
// use less_equal to make it multiset
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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
typedef vector<pair<p64, ll>> vpp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef multiset<ll> ms64;
typedef multiset<p64> msp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef priority_queue<ll> pq64;
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
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())

ll path = 0;

class Graph
{
public:
  ll v;
  vector<ll> *adj;
  Graph(ll x)
  {
    v = x;
    adj = new vector<ll>[v + 1];
  }

  void addEdge(ll i, ll j, bool undir = true)
  {
    adj[i].push_back(j);
    if (undir)
    {
      adj[j].push_back(i);
    }
  }

  void print()
  {
    for (ll i = 0; i <= v; i++)
    {
      cout << i << " --> ";
      for (auto t : adj[i])
      {
        cout << t << " ";
      }
      cout << endl;
    }
  }

  void bfs(ll source, ll end)
  {
    vector<ll> dist(v + 1, INT_MAX), parent(v + 1, -1), vis(v + 1, 0);
    queue<ll> q;
    q.push(source);
    vis[source] = 1;
    dist[source] = 1;
    parent[source] = source;
    while (!q.empty())
    {
      ll curr = q.front();
      q.pop();
      for (auto t : adj[curr])
      {
        if (!vis[t])
        {
          parent[t] = curr;
          vis[t] = 1;
          dist[t] = dist[curr] + 1;
          q.push(t);
        }
      }
    }
    // this will give path from dest--->source
    if (end != -1)
    {
      ll temp = end;
      while (temp != source)
      {
        cout << temp << " --> ";
        temp = parent[temp];
      }
      cout << source << endl;
    }
  }

  void dfshelper(ll v, vector<ll> &vis, s64 &close)
  {
    vis[v] = 1;
    path++;
    // cout << v << " ";
    for (auto child : adj[v])
    {
      if (vis[child] == 0 && close.count(child) == 0)
      {
        dfshelper(child, vis, close);
      }
    }
  }

  void dfs(int source, v64 &vis, s64 &close)
  {
    path = 0;
    dfshelper(source, vis, close);
    // cout << ln;
  }

  void solve()
  {
    ll n, k;
    cin >> n >> k;
    Graph g(n);
    forn(i, k)
    {
      ll a, b;
      cin >> a >> b;
      g.addEdge(a, b);
    }
    v64 order;
    forn(i, n)
    {
      ll x;
      cin >> x;
      order.pb(x);
    }
    s64 close;
    v64 vis(n + 1, 0);
    g.dfs(order.back(), vis, close);
    if (path == n)
    {
      cout << "YES" << ln;
    }
    else
    {
      cout << "NO" << ln;
    }
    // now close order
    forn(i, n - 1)
    {
      close.ie(order[i]);
      fill(all(vis), 0);
      g.dfs(order.back(), vis, close);
      // cout << path << " " << n - i - 1 << ln;
      if (path == n - i - 1)
      {
        cout << "YES" << ln;
      }
      else
      {
        cout << "NO" << ln;
      }
    }
  }

  int main()
  {
    fast_cin();
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
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