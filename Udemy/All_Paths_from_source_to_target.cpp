#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> ans;
map<ll, vector<int>> adj;
vector<int> vis(15, 0);
ll ss;
void dfs(int v, vector<int> &path, int target)
{
    vis[v] = 1;
    path.push_back(v);
    if (v == ss)
    {
        ans.push_back(path);
    }
    else
    {
        for (auto child : adj[v])
        {
            if (vis[child] == 0)
            {
                dfs(child, path, adj.size() - 1);
            }
        }
    }
    // backtrack
    vis[v] = 0;
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph)
{
    ans.clear();
    vis.clear();
    adj.clear();
    ss = graph.size() - 1;
    for (ll i = 0; i < graph.size(); i++)
    {
        auto &x = graph[i];
        for (auto t : x)
        {
            adj[i].push_back(t);
        }
    }
    vector<int> path;
    dfs(0, path, graph.size() - 1);
    return ans;
}