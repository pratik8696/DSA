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
typedef priority_queue<ll> pq64;
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

map<p64, ll> rejected;
ll val1;

bool minCostConnectPoints(vector<pair<pair<ll, ll>, ll>> &points, ll n)
{
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
        else
        {
            // rejected maal
            if (d == 1)
            {
                rejected[{a, b}]++;
            }
            else
            {
                val1++;
            }
        }
    }

    forsn(i, 1, n + 1)
    {
        if (parent[i] == -1)
        {
            return false;
        }
    }
    return true;
}

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        val1 = 0;
        rejected.clear();
        vector<pair<pair<ll, ll>, ll>> first, second;
        // first for first type containing one and three
        for (auto &t : edges)
        {
            auto &x = t;
            if (x[0] == 1)
            {
                first.pb({{x[1], x[2]}, 2});
            }
            else if (x[1] == 2)
            {
                first.pb({{x[1], x[2]}, 2});
            }
            else if (x[2] == 3)
            {
                first.pb({{x[1], x[2]}, 1});
                second.pb({{x[1], x[2]}, 1});
            }
        }
        // second for second type containing two and three
        if (!minCostConnectPoints(first, n))
        {
            return -1;
        }
        if (!minCostConnectPoints(second, n))
        {
            return -1;
        }
        ll ans = val1;
        for (auto t : rejected)
        {
            if (t.se == 2)
            {
                ans++;
            }
        }
        return ans;
    }
};