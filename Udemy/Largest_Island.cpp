#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxi 1000

int arr[maxi][maxi];
int vis[maxi][maxi];
int dist[maxi][maxi];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] == 1 || arr[x][y] == 0)
    {
        return false;
    }
    return true;
}

int dfson2d(int x, int y)
{
    int val = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (isvalid(x + dx[i], y + dy[i]))
        {
            int temp = dfson2d(x + dx[i], y + dy[i]);
            val += temp;
        }
    }
    return val;
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
    n = grid.size();
    m = grid[0].size();
    for (ll i = 0; i < grid.size(); i++)
    {
        for (ll j = 0; j < grid[i].size(); j++)
        {
            arr[i + 1][j + 1] = grid[i][j];
        }
    }
    ll maxx = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (vis[i][j] == 0 && arr[i][j] == 1)
            {
                ll temp = dfson2d(i, j);
                maxx = max(maxx, temp);
            }
        }
    }
    for (ll i = 0; i <= n + 1; i++)
    {
        for (ll j = 0; j <= m + 1; j++)
        {
            vis[i][j] = 0;
            arr[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    return maxx;
}