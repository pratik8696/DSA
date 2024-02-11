// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Back-end complete function Template for C++

class Solution
{
public:
    // Function to perform depth-first search to check if there is a cycle
    // and mark the nodes present in the cycle
    bool dfs(int u, vector<int> adj[], vector<bool> &is_visited,
             vector<bool> &in_stack, vector<bool> &nodes_present_in_cycle)
    {
        is_visited[u] = true;
        in_stack[u] = true;

        // Iterate over the adjacent nodes
        for (auto v : adj[u])
        {
            if (!is_visited[v])
            {
                // Recursively call dfs on unvisited nodes
                bool is_cycle_present =
                    dfs(v, adj, is_visited, in_stack, nodes_present_in_cycle);

                // If cycle is present, mark nodes in the cycle and return true
                if (is_cycle_present)
                {
                    return nodes_present_in_cycle[u] = true;
                }
            }
            else if (is_visited[v] && in_stack[v])
            {
                // If the node is visited and in the recursion stack, cycle is present
                return nodes_present_in_cycle[u] = true;
            }
        }

        // Mark the node as not in recursion stack and return false
        in_stack[u] = false;
        return false;
    }

    // Function to find the eventual safe nodes
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {

        vector<int> safeNodes;
        vector<bool> is_visited(V, false);
        vector<bool> in_stack(V, false);
        vector<bool> nodes_present_in_cycle(V, false);

        // Iterate over all the nodes
        for (int i = 0; i < V; i++)
        {
            if (!is_visited[i])
            {
                // Call dfs for unvisited nodes
                dfs(i, adj, is_visited, in_stack, nodes_present_in_cycle);
            }
        }

        // Add nodes that are not present in any cycle to the safeNodes list
        for (int i = 0; i < V; i++)
        {
            if (!nodes_present_in_cycle[i])
            {
                safeNodes.push_back(i);
            }
        }

        // Return the list of safe nodes
        return safeNodes;
    }
};

int main()
{
    freopen("100000input.txt", "r", stdin);
    freopen("100000output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V+1];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        char x;
        cin >> x;
        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "~\n";
    }
}
