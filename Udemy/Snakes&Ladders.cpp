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

    vector<int> bfs(ll source, ll end)
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
        vector<int> res;
        if (end != -1)
        {
            ll temp = end;
            while (temp != source)
            {
                res.push_back(temp);
                temp = parent[temp];
            }
            res.push_back(source);
        }
        return res;
    }
};

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
    // so i have the start and end of snakes (high to low)
    // and i have the start and end of ladders (low to high)
    // first create the adj list
    Graph g(n);
    // basic connections done
    for (ll i = 1; i < n; i++)
    {
        g.addEdge(i, i + 1, false);
    }
    // now moving to add ladders
    for (auto &t : ladders)
    {
        g.addEdge(t.first, t.second, false);
    }
    // now adding snakes
    for (auto &t : snakes)
    {
        g.addEdge(t.first, t.second, false);
    }
    // now testing
    // g.print();
    // cout<<"Printed"<<endl;
    // testing done
    vector<int> res = g.bfs(1, n);
    reverse(res.begin(), res.end());
    for (auto t : res)
    {
        cout << t << " --> ";
    }
    cout << endl;
    // now counting the no of steps
    ll curr = 0;
    ll ans = 0;
    ll prev = res[0];
    for (ll i = 1; i < res.size(); i++)
    {
        if (res[i] - prev == 1)
        {
            curr++;
        }
        else
        {
            curr = 0;
            ans++;
        }
        if (curr > 6)
        {
            curr = 0;
            ans++;
        }
        prev = res[i];
    }
    return ans + 1;
}
