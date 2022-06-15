typedef long long ll;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

ll n, m;

bool isvalid(int x, int y, vector<int> &vis)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] == 1)
    {
        return false;
    }
    return true;
}

void dfson2d(int x, int y, vector<vector<int>> &heights, vector<int> &vis)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        ll X = x + dx[i];
        ll Y = y + dy[i];
        if (isvalid(x + dx[i], y + dy[i], vis) && heights[x][y] <= heights[X][Y])
        {
            dfson2d(x + dx[i], y + dy[i], heights, vis);
        }
    }
}

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
    }
};