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

    vector<ll> bfs(ll source, ll end = -1)
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
        return dist;
        // // this will give path from dest--->source
        // if (end != -1)
        // {
        //     ll temp = end;
        //     while (temp != source)
        //     {
        //         cout << temp << " --> ";
        //         temp = parent[temp];
        //     }
        //     cout << source << endl;
        // }
    }
};

bool check(string &a, string &b)
{
    int c = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            c++;
        }
    }
    if (c == 1)
    {
        return true;
    }
    return false;
}

int creategraph(vector<string> &wordList)
{
    // for(auto t:wordList)
    // {
    //     cout<<t<<" ";
    // }
    // cout<<endl;
    ll n = wordList.size();
    Graph g(n);
    // use of double for loops
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (check(wordList[i], wordList[j]))
            {
                g.addEdge(i, j);
            }
        }
    }
    vector<ll> dist = g.bfs(0);
    return dist[n - 1] == INT_MAX ? 0 : dist[n - 1];
}

int ladderLength(string beginWord, string endWord, vector<string> wordList)
{

    vector<string> v;
    v.push_back(beginWord);
    bool f = false;
    for (auto t : wordList)
    {
        if (t == endWord)
        {
            f = true;
        }
        v.push_back(t);
    }
    v.push_back(endWord);
    if (f == false)
    {
        return 0;
    }
    return creategraph(v);
}