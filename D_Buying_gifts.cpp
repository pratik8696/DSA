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

void dfson2d(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (isvalid(x + dx[i], y + dy[i]))
        {
            dfson2d(x + dx[i], y + dy[i]);
        }
    }
}