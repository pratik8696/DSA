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

    int dfshelper(ll v, vector<int> &vis)
    {
        vis[v] = 1;
        int val = 1;
        for (auto child : adj[v])
        {
            if (vis[child] == 0)
            {
                val += dfshelper(child, vis);
            }
        }
        return val;
    }

    int dfs(int source, int n)
    {
        ll ans = 1;
        vector<int> vis(v + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                ans *= dfshelper(i, vis);
            }
        }
        return ans;
    }
};

int count_pairs(int N, vector<pair<int, int>> astronauts)
{
    Graph g(N);
    // create the adj list
    for (auto t : astronauts)
    {
        g.addEdge(t.first, t.second);
    }
    return g.dfs(0, N);
}