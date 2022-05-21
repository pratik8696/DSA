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

    void dfshelper(ll v, vector<int> vis)
    {
        vis[v] = 1;
        for (auto child : adj[v])
        {
            if (vis[child] == 0)
            {
                dfshelper(child, vis);
            }
        }
    }

    void dfs(int source, int n)
    {
        vector<int> vis(v + 1, 0);
        dfshelper(source, vis);
    }
};

bool canVisitAllRooms(vector<vector<int>> rooms)
{
    // create the adj list
    ll n = rooms.size();
    Graph g(n);
    for (ll i = 0; i <= n; i++)
    {
        for (auto t : rooms[i])
        {
            g.addEdge(i, t);
        }
    }
    return g.dfs(1, n);
}