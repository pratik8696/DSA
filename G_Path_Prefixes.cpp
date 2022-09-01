#include <bits/stdc++.h>
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

typedef long long ll;
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
typedef vector<pair<p64, ll>> vpp64;
typedef vector<p32> vp32;
typedef map<int, int> m32;
typedef map<ll, ll> m64;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, e) for (int i = 0; i < e; i++)
#define forsn(i, s, e) for (int i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void dfs(int u, v64 &b, ll sum, vv64 adj[], v64 &vis, v64 &ans)
{
    vis[u] = 1;
    int j = upper_bound(all(b), sum) - b.begin();
    ans[u] = j - 1;
    for (auto it : adj[u])
    {
        int i = it[0];

        if (vis[i] == 0)
        {
            b.pb(b.back() + it[2]);
            dfs(i, b, sum + it[1], adj, vis, ans);
            b.pop_back();
        }
    }
}
void Gyani()
{
    ll n, h;
    cin >> n;
    vv64 adj[n + 1];
    v64 vis(n + 1, 0);
    v64 ans(n + 1);
    forn(i, n - 1)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({i + 2, y, z});
        adj[i + 2].push_back({x, y, z});
    }
    v64 b;
    b.pb(0);
    ll sum = 0;
    vis[1] = 1;
    dfs(1, b, sum, adj, vis, ans);

    for (int i = 2; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    fast_cin();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        // cout<<"Case#i: ";
        Gyani();
    }
    return 0;
}