#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int maximumOddSum(vector<int> &parent, vector<int> &weights);

int main()
{
    freopen("2input.txt", "r", stdin);
    freopen("2output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> parent(n);
        vector<int> weights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> parent[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }
        char x;
        cin >> x;
        cout << maximumOddSum(parent, weights) << endl;
        cout << "~" << endl;
    }
}

vector<vector<int>> adj;

vector<int> dfs(int par, int node, vector<int> &wei)
{
    int su = 0;
    int miOdd = 1e9;
    int miEven = 1e9;
    for (int i : adj[node])
    {
        if (i != par)
        {
            vector<int> li = dfs(node, i, wei);
            su += li[0];
            miOdd = min(miOdd, li[1]);
            miEven = min(miEven, li[2]);
        }
    }
    su += wei[node];
    if (wei[node] % 2 == 0)
    {
        miEven = min(miEven, wei[node]);
    }
    else
    {
        miOdd = min(miOdd, wei[node]);
    }
    if (su % 2 == 0)
    {
        if (miOdd != 1e9)
        {
            ans = max(ans, su - miOdd);
        }
    }
    else
    {
        if (miEven < 0)
        {
            ans = max(ans, su - miEven);
        }
        else
        {
            ans = max(ans, su);
        }
    }
    return {su, miOdd, miEven};
}

int maximumOddSum(vector<int> &par, vector<int> &wei)
{
    int n = par.size();
    adj.clear();
    adj.resize(n + 10);
    ans = -1e9;
    for (int i = 1; i < n; i++)
    {
        int u = i;
        int v = par[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(-1, 0, wei);
    if (ans == -1e9)
    {
        ans = -1;
    }
    return ans;
}
