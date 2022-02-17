// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int v, vector<int> adj[], vector<int> vis, vector<int> store)
    {
        vis[v] = 1;
        store.push_back(v);
        for (auto t : adj[v])
        {
            if (vis[t] == 0)
            {
                dfs(t, adj, vis, store);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> store;
        vector<int> vis(V + 1, 0);
        for(int i=0;i<=V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj,vis,store);
            }
        }
        return store;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code EndsF