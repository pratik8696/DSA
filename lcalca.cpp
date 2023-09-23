typedef long long ll;
typedef long double ld;
const ll MOD = 1e9 + 7;

const int MAX_N = 1e5 + 10;
const int LOG = 30;
vector<int> children[MAX_N];
int up[MAX_N][LOG];
int depth[MAX_N];
map<pair<int, int>, int> weights;
vector<vector<int>> freq(MAX_N, vector<int>(26, 0));

void dfs(int a, int par)
{
    for (int b : children[a])
    {
        if (b == par)
            continue;
        depth[b] = depth[a] + 1;
        up[b][0] = a;
        for (int j = 1; j < LOG; j++)
        {
            up[b][j] = up[up[b][j - 1]][j - 1];
        }
        int w = weights[{b, a}];
        freq[b] = freq[a];
        freq[b][w]++;
        dfs(b, a);
    }
}

int LCA(int a, int b)
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (k & (1 << j))
        {
            a = up[a][j];
        }
    }
    if (a == b)
        return a;
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void solve()
{
    ll n = 7;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        children[u].push_back(v);
        children[v].push_back(u);
        weights[{u, v}] = w;
        weights[{v, u}] = w;
    }
    dfs(1, -1);
    vector<vector<int>> queries;
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }
    for (int i = 0; i < q; i++)
    {
        int u = queries[i][0], v = queries[i][1];
        int lca = LCA(u, v);
        vector<int> curr(26, 0);
        int total = 0;
        for (int i = 1; i < 26; i++)
        {
            int times = freq[u][i] + freq[v][i] - (2 * freq[lca][i]);
            curr[i] = times;
            total += times;
        }
        int needed = (total + 1) / 2;
        int cnt = 0, median = -1;
        for (int i = 1; i < 26; i++)
        {
            int val = i, f = curr[i];
            if (f < needed)
                needed -= f;
            else
            {
                median = val;
                break;
            }
        }
        int ans = 0;
        for (int i = 1; i < 26; i++)
        {
            if (curr[i] <= 0)
                continue;
            while (curr[i]--)
                ans += abs(median - i);
        }
        cout << ans << " ";
    }
}

int main()
{
    fast_cin();
    ll test_cases = 1;
    for (ll it = 1; it <= test_cases; it++)
    {
        solve();
    }
    return 0;
}
