#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y, int n, int m)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return false;
    }
    return true;
}

class Solution
{
public:
    bool findingWater(int r, int c, int k, vector<vector<char>> &arr)
    {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> checker(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> d(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        ll distance = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '1')
                {
                    dist[i][j] = 1e9;
                    ll cc = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int x1 = i + dx[k];
                        int y1 = j + dy[k];
                        if (isvalid(x1, y1, n, m))
                        {
                            if (arr[x1][y1] == '1')
                            {
                                cc++;
                            }
                        }
                    }
                    checker[i][j] = cc;
                    if (checker[i][j] < 3)
                    {
                        q.push({i, j});
                    }
                }
            }
        }
        // now we can start the topo sort kind of thing
        while (q.size())
        {
            ll running = q.size();
            distance++;
            while (running--)
            {
                ll curr_x = q.front().first;
                ll curr_y = q.front().second;
                dist[curr_x][curr_y] = distance;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x1 = curr_x + dx[i];
                    int y1 = curr_y + dy[i];
                    if (isvalid(x1, y1, n, m) && arr[x1][y1] == '1')
                    {
                        checker[x1][y1]--;
                        if (checker[x1][y1] == 2)
                        {
                            q.push({x1, y1});
                        }
                    }
                }
            }
        }

        // now let's start the bfs
        q.push({r - 1, c - 1});
        d[r - 1][c - 1] = 0;
        while (q.size())
        {
            ll curr_x = q.front().first;
            ll curr_y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x1 = curr_x + dx[i];
                int y1 = curr_y + dy[i];
                if (isvalid(x1, y1, n, m))
                {
                    if (d[x1][y1] > d[curr_x][curr_y] + 1)
                    {
                        d[x1][y1] = d[curr_x][curr_y] + 1;
                        q.push({x1, y1});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                double first = dist[i][j];
                double second = d[i][j];
                second /= k;
                if (first > second)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c, k;
        cin >> r >> c >> k;
        vector<vector<char>> desert(r, vector<char>(c));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> desert[i][j];
        Solution obj;
        bool res = obj.findingWater(r, c, k, desert);
        cout << res << endl;
    }
}
