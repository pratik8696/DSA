#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;
// use less_equal to make it multiset
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

void solve()
{
    ll n, m;
    cin >> n >> m;
    vp64 adj[n + 10];
    forn(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    v64 dist(n + 10, 1e15);
    set<p64> q;
    q.ie({0, 1});
    dist[1] = 0;
    u64 parent[1] = 1;
    while (!q.empty())
    {
        auto it = *q.begin();
        ll curr_node = it.se;
        ll dist_node = it.fi;
        q.erase(q.begin());
        for (auto child : adj[curr_node])
        {
            ll dist_childtk = child.se;
            ll child_haijo = child.fi;
            if (dist[curr_node] + dist_childtk < dist[child_haijo])
            {
                parent[child_haijo] = curr_node;
                if (q.find({dist[child_haijo], child_haijo}) != q.end())
                {
                    q.erase({dist[child_haijo], child_haijo});
                }
                dist[child_haijo] = dist[curr_node] + dist_childtk;
                q.ie({dist[child_haijo], child_haijo});
            }
        }
    }
    forsn(i, 1, n + 1)
    {
        cout << dist[i] << " ";
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
