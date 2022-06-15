#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
typedef unsigned long long ull;
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
typedef vector<p32> vp32;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define m64 map<ll, ll>
#define mv64 map<ll, v64>
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())

ll curr_cc;

void dfs(ll node, unordered_map<ll, ll> &vis, unordered_map<ll, v64> &adj, unordered_map<ll, ll> &cc)
{
    vis[node] = 1;
    cc[node] = curr_cc;
    for (ll child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, vis, adj, cc);
        }
    }
}

void solve()
{
    ll n, k, a, b;
    cin >> n >> k;
    string op;
    unordered_map<ll, ll> vis, cc;
    unordered_map<ll, v64> adj;
    vp64 edgeList;
    curr_cc = 0;

    forn(i, k)
    {
        cin >> a >> op >> b;
        if (op.compare("=") == 0)
        {
            adj[a].pb(b), adj[b].pb(a);
        }
        else
        {
            edgeList.pb({a, b});
        }
    }

    forsn(i, 1, n + 1)
    {
        if (vis[i] == 0)
        {
            curr_cc++;
            dfs(i, vis, adj, cc);
        }
    }

    bool flag = true;
    if (edgeList.size())
    {
        forn(i, edgeList.size())
        {
            a = edgeList[i].fi;
            b = edgeList[i].se;

            if (cc[a] == cc[b])
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "YES" << ln;
    }
    else
    {
        cout << "NO" << ln;
    }
}

int main()
{
    fast_cin();
    ll t;
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