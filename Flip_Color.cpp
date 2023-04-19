void bfs(uv64 &adj, v64 &dist, ll src)
{
    queue<ll> q;
    v64 vis(dist.size(), 0);
    q.push(src);
    dist[src] = 0;
    vis[src] = 1;
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        for (auto child : adj[curr])
        {
            if (vis[child] == 0)
            {
                dist[child] = dist[curr] + 1;
                q.push(child);
                vis[child]=1;
            }
        }
    }
}