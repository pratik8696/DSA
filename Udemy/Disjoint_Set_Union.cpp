#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxxx 200000
vector<int> parent(maxxx, -1);
int find(ll i);

void union(int a, int b)
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

vector<bool> DSU(vector<vector<int>> query)
{
    vector<bool> ans;
    for (ll i = 0; i < 100001; i++)
    {
        parent[i] = -1;
    }

    for (auto t : query)
    {
        auto x = t;
        if (x[0] == 1)
        {
            union(x[1], x[2]);
        }
        else
        {
            ans.push_back(check(x[1], x[2]));
        }
    }
    return ans;
}
