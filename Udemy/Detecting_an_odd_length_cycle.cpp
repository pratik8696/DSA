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

    bool dfshelper(ll v, vector<int> &vis, int col)
    {
        vis[v] = col;
        for (auto child : adj[v])
        {
            if (vis[child] == 0)
            {
                bool temp = dfshelper(child, vis, 3 - col);
                if (!temp)
                {
                    return false;
                }
            }
            else if (col == vis[child])
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(int source, int n)
    {
        vector<int> vis(v, 0);
        for (ll i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (dfshelper(i, vis, 1) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

bool solve(vector<vector<int>> graph)
{
    Graph g(graph.size());
    for (ll i = 0; i < graph.size(); i++)
    {
        auto &x = graph[i];
        for (auto &t : x)
        {
            g.addEdge(i, t);
        }
    }
    return !g.dfs(0, graph.size());
}