#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    bool dfshelper(ll v, vector<int> &vis, int parent)
    {
        vis[v] = 1;
        for (auto child : adj[v])
        {
            if (vis[child] == 0)
            {
                bool temp = dfshelper(child, vis, v);
                if (temp)
                {
                    return true;
                }
            }
            else if (child != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool dfs(int source, int n)
    {
        ll val = 0;
        vector<int> vis(v + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                val |= dfshelper(i, vis, 0);
            }
        }
        return val;
    }
};

bool solve(int n, vector<vector<int>> edges)
{
    Graph g(n);
    for (auto &t : edges)
    {
        auto &x = t;
        g.addEdge(x[0], x[1]);
    }
    return g.dfs(1, n);
}