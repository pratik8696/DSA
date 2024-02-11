#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Back-end complete function Template for C++
class Solution
{
public:
    int ans = 0;
    void dfs(int v, vector<int> &vis, vector<int> &value, vector<vector<int>> &hsh, vector<vector<int>> &adj, vector<int> &total)
    {
        vis[v] = 1;

        for (auto child : adj[v])
        {
            if (vis[child] == 0)
            {
                dfs(child, vis, value, hsh, adj, total);
                hsh[v][0] += hsh[child][0];
                hsh[v][1] += hsh[child][1];
            }
        }

        if (value[v] > 1)
            hsh[v][value[v] - 2]++;

        int rem2 = total[0] - hsh[v][0];
        int rem3 = total[1] - hsh[v][1];
        int curr_2 = hsh[v][0];
        int curr_3 = hsh[v][1];

        if (rem2 && rem3 && curr_2 && curr_3)
        {
            ans++;
        }
    }

    int splittingEdges(int n, vector<vector<int>> &edges, vector<int> &value)
    {
        vector<vector<int>> adj(n);
        vector<vector<int>> hsh(n, vector<int>(2, 0));
        for (auto t : edges)
        {
            int u = t[0];
            int v = t[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> total(2);
        for (auto t : value)
        {
            if (t > 1)
            {
                total[t - 2]++;
            }
        }

        vector<int> vis(n);
        dfs(0, vis, value, hsh, adj, total);

        return ans;
    }
};

int main()
{
    freopen("10input.txt", "r", stdin);
    freopen("10output.txt", "w", stdout);
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        int N;
        scanf("%d", &N);

        vector<int> Value(N);

        for (int i = 0; i < N; i++)
        {
            cin >> Value[i];
        }

        vector<vector<int>> Edges(N - 1, vector<int>(2));
        Matrix::input(Edges, N - 1, 2);

        char x;
        cin >> x;

        Solution obj;
        int res = obj.splittingEdges(N, Edges, Value);

        cout << res << endl;
        cout << "~" << endl;
    }
}