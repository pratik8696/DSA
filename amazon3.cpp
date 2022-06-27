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
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
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
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash
{
    const uint64_t C = ll(4e18 * acos(0)) | 71;
    ll operator()(p64 x) const { return __builtin_bswap64((x.first ^ x.second ^ RANDOM) * C); }
};

struct node
{
    ll odd;
    unordered_map<ll, ll> freq;
};

void build(ll arr[], node *tree, ll s, ll e, ll tn)
{
    if (s == e)
    {
        tree[tn].freq[arr[s]]++;
        tree[tn].odd = 1;
        return;
    }
    ll mid = (s + e) / 2;
    build(arr, tree, s, mid, 2 * tn);
    build(arr, tree, mid + 1, e, (2 * tn) + 1);
    ll od = 0;
    for (auto t : tree[2 * tn].freq)
    {
        tree[tn].freq[t.fi] += t.se;
    }
    for (auto t : tree[(2 * tn) + 1].freq)
    {
        tree[tn].freq[t.fi] += t.se;
    }
    for (auto t : tree[tn].freq)
    {
        if (t.se % 2)
        {
            od++;
        }
    }
    tree[tn].odd = od;
}

ll query(ll arr[], node *tree, ll s, ll e, ll tn, ll l, ll r)
{
    ll mid = (s + e) / 2;
    // out
    if (s > r || l > e)
    {
        return 0;
    }
    // in
    if (s >= l && r >= e)
    {
        return tree[tn].odd;
    }

    ll ans1 = query(arr, tree, s, mid, 2 * tn, l, r);
    ll ans2 = query(arr, tree, mid + 1, e, (2 * tn) + 1, l, r);
    return ans1 + ans2;
}

void update(ll arr[], node *tree, ll s, ll e, ll tn, ll idx, ll val)
{
    if (s == e)
    {
        tree[tn].odd = 1;
        tree[tn].freq[arr[idx]]--;
        arr[idx] = val;
        tree[tn].freq[arr[idx]]++;
        return;
    }
    ll mid = (s + e) / 2;
    if (idx > mid)
    {
        if (tree[tn].freq[arr[idx]] % 2)
        {
            tree[tn].odd--;
        }
        else
        {
            tree[tn].odd++;
        }
        tree[tn].freq[arr[idx]]--;
        tree[tn].freq[val]++;
        if (tree[tn].freq[val] % 2)
        {
            tree[tn].odd++;
        }
        else
        {
            tree[tn].odd--;
        }
        update(arr, tree, mid + 1, e, (2 * tn) + 1, idx, val);
    }
    else
    {
        if (tree[tn].freq[arr[idx]] % 2)
        {
            tree[tn].odd--;
        }
        else
        {
            tree[tn].odd++;
        }
        tree[tn].freq[arr[idx]]--;
        tree[tn].freq[val]++;
        if (tree[tn].freq[val] % 2)
        {
            tree[tn].odd++;
        }
        else
        {
            tree[tn].odd--;
        }
        update(arr, tree, s, mid, 2 * tn, idx, val);
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll arr[n];
    node tree[4 * n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    build(arr, tree, 0, n - 1, 1);
    while (m--)
    {
        ll val;
        cin >> val;
        if (val == 2)
        {
            ll a, b;
            cin >> a >> b;
            cout << query(arr, tree, 0, n - 1, 1, --a, --b) << " ";
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            update(arr, tree, 0, n - 1, 1, --a, b);
        }
    }
    cout << ln;
}

int main()
{
    fast_cin();
    //#ifndef ONLINE_JUDGE
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    //#endif
    ll t = 1;
    cin >> t;
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
