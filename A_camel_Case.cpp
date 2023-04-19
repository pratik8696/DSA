int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    return true;
}

void bfson2d(int x, int y)
{
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    dist[x][y] = 1;
    q.push(mp(x, y));
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (isvalid(currx + dx[i], curry + dy[i]))
            {
                int x1 = currx + dx[i];
                int y1 = curry + dy[i];
                dist[x1][y1] = dist[currx][curry] + 1;
                vis[x1][y1] = 1;
                q.push(mp(x1, y1));
            }
        }
    }
}