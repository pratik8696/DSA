#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int largestPathValue(string c, vector<vector<int>> edges)
{
    map<ll, ll> indegree;
    for (ll i = 0; i < c.length(); i++)
    {
        indegree[edges[i][1]]++;
    }
    

}