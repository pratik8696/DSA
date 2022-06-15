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

// dsu functions
// void make_set(int v) {
//   parent[v] = v;
//}

// int find_set(int v,v64 &parent) {
//   if (-1 == parent[v])
// return v;
// return find_set(parent[v]);
// }

// void union_sets(int a, int b,v64 &parent) {
//   a = find_set(a,parent);
// b = find_set(b,parent);
// if (a != b)
// parent[b] = a;
// }

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

ll n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
ll sx, sy;
ll ex, ey;

bool isvalid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    return true;
}

void bfson2d(int x, int y, vector<vector<char>> &arr, vv64 &vis, map<p64, p64> &path)
{
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    q.push(mp(x, y));
    path[{x, y}] = {x, y};
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = currx + dx[i];
            int y1 = curry + dy[i];
            if (isvalid(currx + dx[i], curry + dy[i]) && vis[x1][y1] == 0 && arr[x1][y1] != '#')
            {
                vis[x1][y1] = 1;
                q.push(mp(x1, y1));
                path[{x1, y1}] = {currx, curry};
                if (x1 == ex && y1 == ey)
                {
                    return;
                }
            }
        }
    }
}

char action(p64 prev, p64 next)
{
    ll x1 = prev.fi, y1 = prev.se;
    ll x2 = next.fi, y2 = next.se;
    if (y2 - y1 < 0)
    {
        return 'L';
    }
    if (y2 - y1 > 0)
    {
        return 'R';
    }
    if (x2 - x1 > 0)
    {
        return 'D';
    }
    return 'U';
}

void solve()
{
    cin >> n >> m;
    vector<vector<char>> arr(n + 10, vector<char>(m + 10, '#'));
    vector<vector<ll>> vis(n + 10, vector<ll>(m + 10, 0));
    map<p64, p64> path;
    forsn(i, 1, n + 1)
    {
        forsn(j, 1, m + 1)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            if (arr[i][j] == 'B')
            {
                ex = i;
                ey = j;
            }
        }
    }
    bfson2d(sx, sy, arr, vis, path);
    if (!vis[ex][ey])
    {
        cout << "NO" << ln;
        return;
    }
    cout << "YES" << ln;
    p64 prev = {ex, ey};
    p64 source = {sx, sy};
    string s = "";
    vp64 res;
    while (prev != source)
    {
        res.pb(prev);
        prev = path[prev];
    }
    res.pb(prev);
    reverse(all(res));
    forn(i, res.size() - 1)
    {
        s.pb(action(res[i], res[i + 1]));
    }
    cout << s.length() << ln;
    cout << s << ln;
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
