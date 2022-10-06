#include <bits/stdc++.h>
// For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define loops(i, a, b, step) for (int i = a; i < b; i += step)
#define looprs(i, a, b, step) for (int i = a; i >= b; i -= step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);
#define all(a) a.begin(), a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

void buildTree(ll *tree, ll *a, ll index, ll s, ll e)
{
    // base case
    if (s > e)
        return;
    // reached leaf node
    if (s == e)
    {
        tree[index] = a[s];
        return;
    }
    // now build the segment tree in bottom up manner
    int m = (s + e) / 2;
    buildTree(tree, a, 2 * index, s, m);
    buildTree(tree, a, 2 * index + 1, m + 1, e);
    tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    return;
}

// function to query the segment tree for RMQ
ll query(ll *tree, ll index, ll s, ll e, ll qs, ll qe)
{
    // base case: if query range is outside the node range
    if (qs > e || s > qe)
        return INT_MIN;
    // complete overlap
    if (s >= qs && e <= qe)
        return tree[index];
    // now partial overlap case is executed
    ll m = (s + e) / 2;
    ll left_ans = query(tree, 2 * index, s, m, qs, qe);
    ll right_ans = query(tree, 2 * index + 1, m + 1, e, qs, qe);
    return max(left_ans, right_ans);
}

// function to update a value at position to "pos"
void updateNode(ll *arr, ll *tree, ll index, ll s, ll e, ll pos, ll val)
{
    if (pos < s || pos > e)
        return;
    if (s == e)
    {
        arr[s] = val;
        tree[index] = val;
        return;
    }
    ll m = (s + e) / 2;
    updateNode(arr, tree, 2 * index, s, m, pos, val);
    updateNode(arr, tree, 2 * index + 1, m + 1, e, pos, val);
    tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    return;
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    ll idx, val;
    ll arr[n], diff[n], tree[4 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        diff[i] = abs(min(arr[i + 1] - arr[i], 0ll));
    }
    buildTree(tree, diff, 1, 0, n - 2);
    for (int i = 0; i < q; i++)
    {
        cin >> idx >> val;
        arr[idx - 1] = val;
        --idx;
        if (idx == 0)
        {
            updateNode(diff, tree, 1, 0, n - 2, idx, abs(min(arr[idx + 1] - arr[idx], 0ll)));
        }
        else if (idx == n - 1)
        {
            updateNode(diff, tree, 1, 0, n - 2, idx - 1, abs(min(arr[idx] - arr[idx - 1], 0ll)));
        }
        else if (idx > 0 && idx < n - 1)
        {
            updateNode(diff, tree, 1, 0, n - 2, idx, abs(min(arr[idx + 1] - arr[idx], 0ll)));
            updateNode(diff, tree, 1, 0, n - 2, idx - 1, abs(min(arr[idx] - arr[idx - 1], 0ll)));
        }
        cout << query(tree, 1, 0, n - 2, 0, n - 2) << endl;
    }
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}