#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define maxi 1001
char arr[maxi][maxi];
int vis[maxi][maxi];
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
bool dfson2d(ll x, ll y, ll px, ll py)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        ll X = x + dx[i];
        ll Y = y + dy[i];
        ll res = arr[X][Y] == arr[x][y];
        if (isvalid(X, Y) && res)
        {
            if (vis[X][Y] == 0)
            {
                if (dfson2d(X, Y, x, y))
                {
                    return true;
                }
            }
            else if (X != px && Y != py)
            {
                return true;
            }
        }
    }
    return false;
}

bool containsCycle(vector<vector<char>> grid)
{
    n = grid.size();
    m = grid[0].size();
    cout << n << " " << m << endl;
    if (n < 2 || m < 2)
    {
        return false;
    }
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            vis[i][j] = 0;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            arr[i + 1][j + 1] = grid[i][j];
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (vis[i][j] == 0)
            {
                // modify isvalid or just change the condition in dfs
                if (dfson2d(i, j, -1, -1))
                {
                    return true;
                }
            }
        }
    }
    // cout<<endl;
    return false;
}