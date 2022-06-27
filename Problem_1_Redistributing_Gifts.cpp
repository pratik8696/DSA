#include <bits/stdc++.h>

using namespace std;
const int N = 501;

// The adjacency lists for the graph (revgraph is reversed)
vector<int> graph[N], revgraph[N];
vector<bool> vis(N), vis2(N);
vector<int> path;

// Stores all nodes in a SCC
set<int> comp;

// DFS functions for Kosaraju's
void dfs(int node)
{
    vis[node] = true;
    for (int i : graph[node])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    path.push_back(node);
}

void dfs2(int node)
{
    vis2[node] = true;
    for (int i : revgraph[node])
    {
        if (!vis2[i])
        {
            dfs2(i);
        }
    }
    comp.insert(node);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // The graph array contains the cow i's preferred gifts (and itself).
        graph[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
        /*
         * We don't want edges to non-preferred gifts,
         * so we remove all gifts after its original assignment.
         */
        while (graph[i].back() != i)
        {
            graph[i].pop_back();
        }
        for (int j : graph[i])
        {
            revgraph[j].push_back(i);
        }
    }

    // classic kosaraju implementation
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    reverse(path.begin(), path.end());

    vector<int> ans(n + 1);
    for (int i : path)
    {
        if (!vis2[i])
        {
            dfs2(i);
            /*
             * Loop over all cows in the SCC and its preference list.
             * If a gift is found in its preference and also in the SCC,
             * just assign the it to the cow.
             */
            for (int j : comp)
            {
                for (int k : graph[j])
                {
                    if (comp.count(k))
                    {
                        ans[j] = k;
                        break;
                    }
                }
            }
            comp.clear();
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}