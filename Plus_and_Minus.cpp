
void dfs(int v, v64 &vis, uv64 &adj)
{
    vis[v] = 1;
    for (auto child : adj[v])
    {
        if (vis[child] == 0)
        {
            dfs(child, vis, adj);
        }
    }
}