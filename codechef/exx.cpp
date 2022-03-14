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
#typedef vector<ll> v64;
#define maxi 300002
map<ll, v64> arr;
int vis[maxi];

v64 idx;
void dfs(int v, ll a[])
{
    vis[v] = 1;
    idx.pb(v);
    for (auto child : arr[v])
    {
        if (vis[child] == 0)
        {
            dfs(child, a);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    map<ll, v64> m;
    forn(i, n)
    {
        cin >> a[i];
        for (ll j = 0; j < 32; j++)
        {
            ll res = powl(2, j);
            if (res & a[i])
            {
                m[j].pb(i);
            }
        }
    }
    for (auto t : m)
    {
        auto v = t.se;
        for (ll i = 0; i < v.size() - 1; i++)
        {
            arr[v[i]].pb(v[i + 1]);
            arr[v[i + 1]].pb(v[i]);
        }
    }
    map<ll, ll> res;
    // now do dfs
    for (ll i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, a);
            v64 s;
            for (auto t : idx)
            { 
                s.pb(a[t]);
            }
            sort((s.begin()),s.end());
            sort((idx.begin()),idx.end());
            for (ll i = 0; i < s.size(); i++)
            {
                res[idx[i]] = s[i];
            }
            idx.clear();
        }
    }
    sort(arr,arr+n);
    bool flag = 1;
    for (ll i = 0; i < n; i++)
    {
        if (res[i] != a[i])
        {
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "Yes" << ln;
    }
    else
    {
        cout << "No" << ln;
    }
    forn(i, n)
    {
        vis[i] = 0;
    }
    arr.clear();
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