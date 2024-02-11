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

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A, int N)
    {
        if (A.size() != N)
            return;
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// Back-end complete function Template for C++

class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &topo)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                dfs(it, adj, vis, topo);
            }
        }
        topo.push_back(node);
    }

    vector<int> createArray(int M, int N, vector<vector<int>> &Requirements)
    {

        vector<int> adj[N];
        for (auto i : Requirements)
        {
            adj[i[0]].push_back(i[1]);
        }

        vector<int> topo;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, adj, vis, topo);
            }
        }
        reverse(topo.begin(), topo.end());

        vector<int> answer(N, 1);

        queue<int> q;
        for (auto i : topo)
        {
            q.push(i);
        }

        while (q.size())
        {
            int node = q.front();
            q.pop();

            for (auto i : adj[node])
            {
                if (answer[i] <= answer[node])
                {
                    answer[i] = answer[node] + 1;
                    q.push(i);
                }
            }
        }

        return answer;
    }
};

int main()
{
    freopen("1000input.txt", "r", stdin);
    freopen("1000out.txt", "w", stdout);
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int M;
        scanf("%d", &M);

        int N;
        scanf("%d", &N);

        vector<vector<int>> Requirements(M, vector<int>(2));
        Matrix::input(Requirements, M, 2);

        Solution obj;
        char x;
        cin >> x;
        vector<int> res = obj.createArray(M, N, Requirements);

        Array::print(res, N);
        cout << "~" << endl;
    }
}
