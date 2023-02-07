#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
vector<int> v, tree;
void build(int node, int s, int e)
{
    if (s == e)
    {
        tree[node] = v[s];
        return;
    }
    int m = (s + e) / 2;
    build(2 * node, s, m);
    build(2 * node + 1, m + 1, e);
    tree[node] = __gcd(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int s, int e, int l, int r)
{
    if (l > e || r < s)
        return 0;
    if (l <= s && r >= e)
        return tree[node];
    int m = (s + e) / 2;
    return __gcd(query(2 * node, s, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}
signed main()
{
    int n;
    cin >> n;
    v.resize(n);
    tree.resize(4 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    build(1, 0, n - 1);
    int i = 0, j = 0;
    int res = INT64_MAX;
    int curr_gcd = 0;
    while (j < n)
    {
        curr_gcd = __gcd(curr_gcd, v[j]);
        if (curr_gcd == 1)
        {
            while (curr_gcd == 1)
            {
                res = min(res, j - i + 1);
                i++;
                curr_gcd = query(1, 0, n - 1, i, j);
            }
        }
        j++;
    }
    cout << (res == 2e18 ? -1 : res) << endl;
    return 0;
}