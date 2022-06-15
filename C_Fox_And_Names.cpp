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
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())

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

    bool dfshelper(ll v, vector<bool> &vis, vector<bool> &stack)
    {
        vis[v] = 1;
        stack[v] = 1;

        // we will find the backedge here
        for (auto child : adj[v])
        {
            // if backedge is found
            if (stack[child])
            {
                return true;
            }
            else if (vis[child] == 0)
            {
                // recursively returning the true val
                bool temp = dfshelper(child, vis, stack);
                if (temp)
                {
                    return true;
                }
            }
        }
        // if nothing is found then here
        // removing elements from path
        stack[v] = 0;
        return false;
    }

    bool dfs()
    {
        vector<bool> vis(v + 1, false), stack(v + 1, false);
        for (ll i = 1; i <= v; i++)
        {
            if (vis[i] == 0)
            {
                if (dfshelper(i, vis, stack))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

void solve()
{
    ll n;
    cin >> n;
    vector<string> s;
    forn(i, n)
    {
        string t;
        cin >> t;
        s.pb(t);
    }
    vector<pair<char, char>> res;
    forn(j, n - 1)
    {
        string a = s[j];
        string b = s[j + 1];
        if (a.length() <= b.length())
        {
            for (ll i = 0; i < a.length(); i++)
            {
                if (a[i] < b[i])
                {
                    res.pb({a[i], b[i]});
                    break;
                }
                else if (a[i] == b[i])
                {
                    continue;
                }
                else
                {
                    res.pb({a[i], b[i]});
                    break;
                }
            }
        }
        else
        {
            bool valid = false;
            forn(i, b.length())
            {
                if (a[i] < b[i])
                {
                    res.pb({a[i], b[i]});
                    valid=1;
                    break;
                }
                else if (a[i] == b[i])
                {
                    continue;
                }
                else
                {
                    res.pb({a[i], b[i]});
                    valid=1;
                    break;
                }
            }
            if (!valid)
            {
                cout << "Impossible" << ln;
                return;
            }
        }
    }
    Graph g(27);
    map<ll, ll> indegree;
    map<ll, v64> ss;
    s64 vals;
    for (auto t : res)
    {
        ll x = t.fi - '0' - 48, y = t.se - '0' - 48;
        g.addEdge(x, y, false);
        ss[x].pb(y);
        vals.ie(x);
        vals.ie(y);
        indegree[y]++;
    }
    if (g.dfs())
    {
        cout << "Impossible" << ln;
        return;
    }

    // bfs way to get topo
    queue<int> q;
    for (auto t : vals)
    {
        if (indegree[t] == 0)
        {
            q.push(t);
        }
    }
    string ans = "";
    s64 rep;
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        char xx = curr + 'a' - 1;
        ans.pb(xx);
        rep.ie(xx);
        for (auto t : ss[curr])
        {
            indegree[t]--;
            if (indegree[t] == 0)
            {
                q.push(t);
            }
        }
    }
    for (char z = 'a'; z <= 'z'; z++)
    {
        if (rep.count(z) == 0)
        {
            ans.pb(z);
        }
    }
    cout << ans << ln;
}

int main()
{
    fast_cin();
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
