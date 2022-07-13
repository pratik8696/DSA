#include <bits/stdc++.h>
#define MAX 100005
#define INF 1000000009

using namespace std;

int A[MAX];
int val[MAX];
vector<int> v[MAX];
vector<int> rev_v[MAX];
vector<int> scc_v[MAX];
vector<pair<int, int>> edges;
bool vis[MAX];
int comp[MAX];
stack<int> s;
int components;
set<int> ss[MAX];

/**
 * Push the vertices in the stack in the decreasing order
 * of their finishing times.
 *
 * First DFS of the Kosaraju Algorithm
 **/
void dfs_0(int curr)
{
    vis[curr] = true;
    for (int i = 0; i < (int)v[curr].size(); i++)
    {
        if (vis[v[curr][i]])
            continue;
        dfs_0(v[curr][i]);
    }
    s.push(curr);
}

void dfs_1(int curr)
{
    vis[curr] = true;
    comp[curr] = components;
    val[components] = __gcd(val[components], A[curr]);
    for (int i = 0; i < (int)rev_v[curr].size(); i++)
    {
        if (vis[rev_v[curr][i]])
            continue;
        dfs_1(rev_v[curr][i]);
    }
}

void dfs_2(int curr)
{
    vis[curr] = true;
    for (int i = 0; i < (int)scc_v[curr].size(); i++)
    {
        if (vis[scc_v[curr][i]])
            continue;
        dfs_2(scc_v[curr][i]);
    }
    s.push(curr);
    cout << curr << " ";
}

int main()
{
    int n, m, x, y;

    cin >> n >> m;
    assert(n >= 1 && n <= 100000);
    assert(m >= 1 && m <= 100000);

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        assert(A[i] >= 1 && A[i] <= 100000);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        assert(x >= 1 && x <= n);
        assert(y >= 1 && y <= n);
        edges.push_back(make_pair(x, y));
        v[x].push_back(y);
        rev_v[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs_0(i);
    }

    memset(vis, false, sizeof(vis));

    components = 0;

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        if (!vis[curr])
        {
            components++;
            dfs_1(curr);
        }
    }

    // Create an scc condensed dag graph
    // Number of vertices = components
    // Edges -> scc[]
    // Value on each node of this scc - val[i]
    for (int i = 0; i < m; i++)
    {
        if (comp[edges[i].first] != comp[edges[i].second])
        {
            scc_v[comp[edges[i].first]].push_back(comp[edges[i].second]);
        }
    }

    memset(vis, false, sizeof(vis));

    // Perform a topological sort on this.

    for (int i = 1; i <= components; i++)
    {
        if (!vis[i])
            dfs_2(i);
    }
    cout << endl;

    int ans = INF;

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        ss[curr].insert(val[curr]);
        cout << curr << " ---START" << endl;
        ans = min(ans, val[curr]);
        for (set<int>::iterator it = ss[curr].begin(); it != ss[curr].end(); it++)
        {
            for (int j = 0; j < (int)scc_v[curr].size(); j++)
            {
                int vall = __gcd(*it, val[scc_v[curr][j]]);
                cout << scc_v[curr][j] << " " << *it << " " << vall << " | ";
                ss[scc_v[curr][j]].insert(vall);
                ans = min(ans, vall);
            }
            cout << endl;
        }
    }

    cout << ans << endl;

    return 0;
}
