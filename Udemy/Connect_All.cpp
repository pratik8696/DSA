typedef long long ll;
typedef vector<ll> v64;

int find_set(int v, v64 &parent)
{
    if (-1 == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, v64 &parent)
{
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b)
        parent[b] = a;
}

bool compare(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    return a.second < b.second;
}

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        ll n = points.size();
        vector<pair<pair<ll, ll>, ll>> edges;
        for (ll i = 0; i < n - 1; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                ll dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({{i, j}, dist});
            }
        }
        sort(edges.begin(), edges.end(), compare);
        vector<ll> parent(n + 1, -1);
        ll ans = 0;
        for (auto t : edges)
        {
            ll a = t.first.first;
            ll b = t.first.second;
            ll d = t.second;
            a = find_set(a, parent);
            b = find_set(b, parent);
            ll p1 = min(a, b);
            ll p2 = max(a, b);
            if (p1 != p2)
            {
                union_sets(p1, p2, parent);
                ans += d;
            }
        }
        return ans;
    }
};