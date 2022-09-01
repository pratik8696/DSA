#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
// use less_equal to make it multiset
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef vector<pair<p64, ll>> vpp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef multiset<ll> ms64;
typedef multiset<p64> msp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef unordered_map<ll, v64> uv64;
typedef unordered_map<ll, ll> u64;
typedef unordered_map<p64, ll> up64;
typedef unordered_map<ll, vp64> uvp64;
typedef priority_queue<ll> pq64;
typedef priority_queue<ll, v64, greater<ll>> pqs64;
const int MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(p64 x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ splitmix64(x.second + FIXED_RANDOM);
    }
    size_t operator()(ll x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef gp_hash_table<ll, ll, custom_hash> fm64;
typedef gp_hash_table<p64, ll, custom_hash> fmp64;

#define ln "\n"
#define mp make_pair
#define ie insert
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())
#define dbg(a) cout << a << endl;
#define dbg2(a) cout << a << ' ';
using ld = long double;
using db = double;
using str = string; // yay python!
// INPUT
#define tcT template <class T
#define tcTU tcT, class U
#define tcTUU tcT, class... U
tcT > void re(T &x)
{
    cin >> x;
}
tcTUU > void re(T &t, U &...u)
{
    re(t);
    re(u...);
}

struct hotel
{
    string s = "";
    int price = 0;
    double rating = 0;
};

void dfs(int v, v64 &vis, uv64 &adj)
{
    vis[v] = 1;
    for (auto child : adj[v])
    {
        if (vis[child] == 0)
        {
            dfs(child, vis, adj);
        }
    }
}

void build(vector<hotel> &arr, vector<hotel> &tree, ll s, ll e, ll tn)
{
    if (s == e)
    {
        tree[tn].rating = arr[s].rating;
        tree[tn].s = arr[s].s;
        return;
    }
    ll mid = (s + e) / 2;
    build(arr, tree, s, mid, 2 * tn);
    build(arr, tree, mid + 1, e, (2 * tn) + 1);
    if (tree[2 * tn].rating >= tree[(2 * tn) + 1].rating)
    {
        tree[tn].rating = tree[2 * tn].rating;
        tree[tn].s = tree[2 * tn].s;
    }
    else if (tree[2 * tn].rating > tree[(2 * tn) + 1].rating)
    {
        tree[tn].rating = tree[(2 * tn) + 1].rating;
        tree[tn].s = tree[(2 * tn) + 1].s;
    }
}

hotel query(vector<hotel> &arr, vector<hotel> &tree, ll s, ll e, ll tn, ll l, ll r)
{
    ll mid = (s + e) / 2;
    // out
    if (s > r || l > e)
    {
        hotel temp;
        return temp;
    }
    // in
    if (s >= l && r >= e)
    {
        return tree[tn];
    }

    hotel ans1 = query(arr, tree, s, mid, 2 * tn, l, r);
    hotel ans2 = query(arr, tree, mid + 1, e, (2 * tn) + 1, l, r);

    if (ans1.rating >= ans2.rating)
    {
        // cout << ans1.rating << ln;
        return ans1;
    }
    // cout << ans2.rating << ln;
    return ans2;
}

bool compare(hotel &a, hotel &b)
{
    if (a.price < b.price)
    {
        return a;
    }
    else if (a.price == b.price)
    {
    }
    return b;
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<hotel> arr(n), tree(4 * n);
    forn(i, n)
    {
        string x;
        int val;
        double rate;
        cin >> x >> val >> rate;
        arr[i].rating = rate;
        arr[i].s = x;
        arr[i].price = val;
    }
    sort(all(arr), compare);

    build(arr, tree, 0, arr.size() - 1, 1);
    forn(i, q)
    {
        ll a, b;
        cin >> a >> b;
        hotel x = query(arr, tree, 0, arr.size() - 1, 1, a, b);
        cout << x.s << ln;
    }
}
int main()
{
    fast_cin();
    //#ifndef ONLINE_JUDGE
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    //#endif
    ll t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}

/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
*/
