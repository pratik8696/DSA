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

// dsu functions
// void make_set(int v) {
//   parent[v] = v;
//}

// int find_set(int v,v64 &parent) {
//   if (-1 == parent[v])
// return v;
// return parent[v]=find_set(parent[v],parent);
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

struct node
{
    ll val_one;
    ll val_zero;
    node()
    {
        val_one = 0;
        val_zero = 0;
    }
};

void build(ll arr[], node tree[], ll s, ll e, ll tn)
{
    if (s == e)
    {
        if (arr[s])
        {
            tree[tn].val_one = (s + 1) * (s + 1);
        }
        else
        {
            tree[tn].val_zero = (s + 1) * (s + 1);
        }
        return;
    }
    ll mid = (s + e) / 2;
    build(arr, tree, s, mid, 2 * tn);
    build(arr, tree, mid + 1, e, (2 * tn) + 1);
    tree[tn].val_one = tree[2 * tn].val_one + tree[(2 * tn) + 1].val_one;
    tree[tn].val_zero = tree[2 * tn].val_zero + tree[(2 * tn) + 1].val_zero;
}

ll query(ll arr[], node tree[], ll s, ll e, ll tn, ll l, ll r, ll lazy[])
{
    if (lazy[tn] != 0)
    {
        ll x = lazy[tn];
        lazy[tn] = 0;
        if (x % 2)
        {
            ll temp = tree[tn].val_one;
            tree[tn].val_one = tree[tn].val_zero;
            tree[tn].val_zero = temp;
            if (s != e)
            {
                lazy[2 * tn] += 1;
                lazy[(2 * tn) + 1] += 1;
            }
        }
    }

    ll mid = (s + e) / 2;
    // out
    if (s > r || l > e)
    {
        return 0;
    }
    // in
    if (s >= l && r >= e)
    {
        return tree[tn].val_one;
    }

    ll ans1 = query(arr, tree, s, mid, 2 * tn, l, r, lazy);
    ll ans2 = query(arr, tree, mid + 1, e, (2 * tn) + 1, l, r, lazy);
    return ans1 + ans2;
}

void update(ll arr[], node tree[], ll s, ll e, ll tn, ll l, ll r, ll val, ll lazy[])
{
    if (lazy[tn] != 0)
    {
        ll x = lazy[tn];
        lazy[tn] = 0;
        if (x % 2)
        {
            ll temp = tree[tn].val_one;
            tree[tn].val_one = tree[tn].val_zero;
            tree[tn].val_zero = temp;
            if (s != e)
            {
                lazy[2 * tn] += 1;
                lazy[(2 * tn) + 1] += 1;
            }
        }
    }

    // out
    if (s > r || l > e)
    {
        return;
    }
    // in
    if (s >= l && r >= e)
    {
        // insert in lazy
        // swap kro yha pr
        ll temp = tree[tn].val_one;
        tree[tn].val_one = tree[tn].val_zero;
        tree[tn].val_zero = temp;
        if (s != e)
        {
            lazy[2 * tn] += 1;
            lazy[(2 * tn) + 1] += 1;
        }
        return;
    }

    ll mid = (s + e) / 2;
    update(arr, tree, mid + 1, e, (2 * tn) + 1, l, r, val, lazy);
    update(arr, tree, s, mid, 2 * tn, l, r, val, lazy);
    tree[tn].val_one = tree[2 * tn].val_one + tree[(2 * tn) + 1].val_one;
    tree[tn].val_zero = tree[2 * tn].val_zero + tree[(2 * tn) + 1].val_zero;
}

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll arr[n];
    forn(i, n)
    {
        if (s[i] == '1')
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
    node tree[4 * n];
    ll lazy[4 * n];
    memset(lazy, 0, sizeof(lazy));
    build(arr, tree, 0, n - 1, 1);
    ll q;
    cin >> q;
    while (q--)
    {
        ll type;
        cin >> type;
        ll a, b;
        cin >> a >> b;
        a--, b--;
        if (type == 2)
        {
            ll sum = 0;
            for (ll i = a, j = 1; i <= b; i++, j++)
            {
                // ll value = query(arr, tree, 0, n - 1, 1, i, i, lazy);
                // cout << value << " ";
                sum += (query(arr, tree, 0, n - 1, 1, i, i, lazy) > 0 ? j * j : 0);
            }
            // cout << endl;
            cout << sum << endl;
        }
        else
        {
            update(arr, tree, 0, n - 1, 1, a, b, 0, lazy);
        }
    }
    return 0;
}