#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxxx 200000
vector<int> parent(maxxx, -1);

int find(ll i);
void unite(int a, int b)
{
    ll s1 = find(a);
    ll s2 = find(b);
    if (s1 != s2)
    {
        parent[s2] = s1;
    }
}

bool check(ll a, ll b)
{
    ll s1 = find(a);
    ll s2 = find(b);
    if (s1 != s2)
    {
        return false;
    }
    return true;
}

int find(ll i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return find(parent[i]);
}

bool solve(vector<vector<int>> edges)
{
    vector<bool> ans;
    for (ll i = 0; i < 100001; i++)
    {
        parent[i] = -1;
    }
    for (auto t : edges)
    {
        auto x = t;
        ll s1 = find(x[0]);
        ll s2 = find(x[1]);
        if (s1 != s2)
        {
            unite(s1, s2);
        }
        else
        {
            return !true;
        }
    }
    return !false;
}
