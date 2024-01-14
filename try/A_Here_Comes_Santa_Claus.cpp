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

// function for prime factorization
vector<pair<ll, ll>> pf(ll n)
{
    vector<pair<ll, ll>> prime;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n = n / i;
            }
            prime.pb(mp(i, count));
        }
    }
    if (n > 1)
    {
        prime.pb(mp(n, 1));
    }
    return prime;
}

// sum of digits of a number
ll sumofno(ll n)
{
    ll sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

// modular exponentiation
long long modpow(long long x, long long n, long long p)
{

    if (n == 0)
        return 1 % p;

    ll ans = 1, base = x;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = (ans * base) % p;
            n--;
        }
        else
        {
            base = (base * base) % p;
            n /= 2;
        }
    }
    if (ans < 0)
        ans = (ans + p) % p;
    return ans;
}

// const int N = 1e6 + 100;
// long long fact[N];
//  initialise the factorial
// void initfact(){
// fact[0] = 1;
// for (int i = 1; i < N; i++)
//{
// fact[i] = (fact[i - 1] * i);
// fact[i] %= MOD;
// }}

// formula for c
// ll C(ll n, ll i)
//{
// ll res = fact[n];
// ll div = fact[n - i] * fact[i];
// div %= MOD;
// div = modpow(div, MOD - 2, MOD);
// return (res * div) % MOD;
// }

long long CW(ll n, ll m)
{
    if (m > n - m)
        m = n - m;
    long long ans = 1;
    for (int i = 0; i < m; i++)
    {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

// function for fast expo
ll fastexpo(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (a == 0)
    {
        return 0;
    }
    ll y = fastexpo(a, b / 2);
    if (b % 2 == 0)
    {
        return y * y;
    }
    else
    {
        return a * y * y;
    }
}

ll popcount(ll n)
{
    ll c = 0;
    for (; n; ++c)
        n &= n - 1;
    return c;
}

ll ce(ll x, ll y)
{
    ll res = x / y;
    if (x % y != 0)
    {
        res++;
    }
    return res;
}

bool pow2(ll x)
{
    ll res = x & (x - 1);
    if (res == 0)
    {
        return true;
    }
    return false;
}

bool isPrime(int x)
{
    for (int d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}

void bfs(vv64 &adj, v64 &dist, ll source, v64 &parent)
{
    queue<ll> q;
    q.push(source);
    dist[source] = 0;
    parent[source] = 0;
    while (q.size())
    {
        ll curr = q.front();
        q.pop();
        for (ll child : adj[curr])
        {
            if (dist[child] > dist[curr] + 1)
            {
                dist[child] = dist[curr] + 1;
                parent[child] = curr;
                q.push(child);
            }
        }
    }
}

void dfs(ll v, v64 &vis, vv64 &adj, v64 &counter)
{
    vis[v] = 1;
    for (ll child : adj[v])
    {
        if (vis[child] == 0)
        {
            dfs(child, vis, adj, counter);
            counter[v] += counter[child];
        }
    }
}

class Solution
{
public:
    long long findMin(int n, int m, vector<int> &p, vector<int> &w, vector<int> &source, vector<int> &destination)
    {
        vv64 adj(n);
        for (int i = 1; i < n; i++)
        {
            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);
        }
        v64 parent(n, 0);
        int sparse[n][30];
        memset(sparse, 0, sizeof(sparse));
        v64 lvl(n, 1e16);
        bfs(adj, lvl, 0, parent);
        forsn(i, 0, n)
        {
            sparse[i][0] = parent[i];
        }
        for (ll j = 1; j < 30; j++)
        {
            for (ll i = 0; i < n; i++)
            {
                sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
            }
        }
        v64 counter(n);
        for (ll z = 0; z < m; z++)
        {
            ll a = destination[z], b = source[z];
            counter[a] += 1;
            counter[b] += 1;
            ll rem = lvl[a] - lvl[b];
            if (rem < 0)
            {
                swap(a, b);
            }
            ll steps = abs(rem);
            while (steps)
            {
                // a needs to come up
                a = sparse[a][__lg(steps)];
                steps -= pow(2, __lg(steps));
            }
            // cout << a << " " << b << ln;
            ll lca = a;
            if (a == b)
            {
                lca = a;
            }
            else
            {
                for (ll i = 30 - 1; i >= 0; i--)
                {
                    if (sparse[a][i] != sparse[b][i])
                    {
                        a = sparse[a][i];
                        b = sparse[b][i];
                    }
                }
                lca = sparse[a][0];
            }
            counter[lca] -= 2;
        }
        v64 vis(n);
        dfs(0, vis, adj, counter);
        sort(begin(w) + 1, end(w));
        sort(begin(counter) + 1, end(counter), greater<ll>());
        unsigned long long ans = 0;
        for (ll i = 1; i < n; i++)
        {
            unsigned long long val1 = counter[i];
            unsigned long long val2 = w[i];
            ans += val1 * val2;
        }
        // cout<<endl;
        return ans;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> p(n), w(n), source(m), destination(m);
        forn(i, n)
        {
            cin >> p[i];
        }
        forn(i, n)
        {
            cin >> w[i];
        }
        forn(i, m)
        {
            cin >> source[i];
        }
        forn(i, m)
        {
            cin >> destination[i];
        }
        Solution sol;
        cout << sol.findMin(n, m, p, w, source, destination) << endl;
    }
}