#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites)
{
    // use always bfs while writing topological sorting code
    map<ll, ll> indegree;
    map<ll, vector<int>> adj;
    for (auto t : prerequisites)
    {
        auto x = t;
        adj[x[1]].push_back(x[0]);
        indegree[x[0]]++;
    }
    // now take the zero indegree ones and add them to a set
    queue<ll> q;
    set<ll> s;
    for (ll i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            s.insert(i);
        }
    }
    for (auto t : s)
    {
        q.push(t);
    }
    vector<int> topo;
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        topo.push_back(curr);
        s.clear();
        for (auto child : adj[curr])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                s.insert(child);
            }
        }
        for (auto t : s)
        {
            q.push(t);
        }
    }
    for (auto t : topo)
    {
        cout << t << " ";
    }
    if(topo.size()!=numCourses)
    {
        return {};
    }
    cout << endl;
    return topo;
}