// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find unit area of the largest region of 1s.
    int n, m;
    int vis[1000][1000];
    int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
    int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
    bool isvalid(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 1)
        {
            return false;
        }
        if (grid[x][y] == 1)
        {
            return true;
        }
        if (grid[x][y] == 0)
        {
            return false;
        }
        return true;
    }

    int cc;
    void dfson2d(int x, int y, vector<vector<int>> &grid)
    {
        vis[x][y] = 1;
        cc++;
        for (int i = 0; i < 8; i++)
        {
            if (isvalid(x + dx[i], y + dy[i], grid))
            {
                dfson2d(x + dx[i], y + dy[i], grid);
            }
        }
    }

    int findMaxArea(vector<vector<int>> &grid)
    {
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                vis[i][j] = 0;
            }
        }
        n = grid.size();
        m = grid[0].size();
        vector<pair<int, int>> v;
        int result = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    dfson2d(i, j, grid);
                    cout << cc << " ";
                    cc = 0;
                }
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends