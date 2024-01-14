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
// typedef treee<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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

class Node
{
public:
    queue<p32> res;
    Node()
    {
    }
};

const int val = 2e5 + 10;
ll arr[val], treee[4 * val];
Node lazy[4 * val];

void build(ll s, ll e, ll tn)
{
    if (s == e)
    {
        treee[tn] = arr[s];
        return;
    }
    ll mid = (s + e) / 2;
    build(s, mid, 2 * tn);
    build(mid + 1, e, (2 * tn) + 1);
    treee[tn] = treee[2 * tn] + treee[(2 * tn) + 1];
}

ll query(ll s, ll e, ll tn, ll l, ll r)
{
    while (lazy[tn].res.size() != 0)
    {
        p32 front = lazy[tn].res.front();
        lazy[tn].res.pop();
        ll x = front.first;
        ll type = front.second;
        if (type == 1)
        {
            // just increase the value in the range by x
            treee[tn] += x * (e - s + 1);
            if (s != e)
            {
                lazy[2 * tn].res.push({x, type});
                lazy[(2 * tn) + 1].res.push({x, type});
                // lazy[2 * tn].val += x;
                // lazy[(2 * tn) + 1].val += x;
                // lazy[2 * tn].type = type;
                // lazy[(2 * tn) + 1].type = type;
            }
        }
        else
        {
            // just set the value in the range as x
            treee[tn] = x * (e - s + 1);
            if (s != e)
            {
                lazy[2 * tn].res.push({x, type});
                lazy[(2 * tn) + 1].res.push({x, type});
                // lazy[2 * tn].val = x;
                // lazy[(2 * tn) + 1].val = x;
                // lazy[2 * tn].type = type;
                // lazy[(2 * tn) + 1].type = type;
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
        return treee[tn];
    }

    ll ans1 = query(s, mid, 2 * tn, l, r);
    ll ans2 = query(mid + 1, e, (2 * tn) + 1, l, r);
    return ans1 + ans2;
}

void update(ll s, ll e, ll tn, ll l, ll r, ll val, ll type_of_update)
{
    while (lazy[tn].res.size() != 0)
    {
        p32 front = lazy[tn].res.front();
        lazy[tn].res.pop();
        ll x = front.first;
        ll type = front.second;
        if (type == 1)
        {
            // just increase the value in the range by x
            treee[tn] += x * (e - s + 1);
            if (s != e)
            {
                lazy[2 * tn].res.push({x, type});
                lazy[(2 * tn) + 1].res.push({x, type});
                // lazy[2 * tn].val += x;
                // lazy[(2 * tn) + 1].val += x;
                // lazy[2 * tn].type = type;
                // lazy[(2 * tn) + 1].type = type;
            }
        }
        else
        {
            // just set the value in the range as x
            treee[tn] = x * (e - s + 1);
            if (s != e)
            {
                lazy[2 * tn].res.push({x, type});
                lazy[(2 * tn) + 1].res.push({x, type});
                // lazy[2 * tn].val = x;
                // lazy[(2 * tn) + 1].val = x;
                // lazy[2 * tn].type = type;
                // lazy[(2 * tn) + 1].type = type;
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
        if (type_of_update == 1)
        {
            // just increase the values by x
            treee[tn] += val * (e - s + 1);
            if (s != e)
            {
                lazy[2 * tn].res.push({val, type_of_update});
                lazy[(2 * tn) + 1].res.push({val, type_of_update});
                // lazy[2 * tn].val += val;
                // lazy[2 * tn].type = type_of_update;
                // lazy[(2 * tn) + 1].val += val;
                // lazy[(2 * tn) + 1].type = type_of_update;
            }
        }
        else
        {
            // set the values as val
            treee[tn] = val * (e - s + 1);
            if (s != e)
            {
                lazy[2 * tn].res.push({val, type_of_update});
                lazy[(2 * tn) + 1].res.push({val, type_of_update});
                // lazy[2 * tn].val = val;
                // lazy[2 * tn].type = type_of_update;
                // lazy[(2 * tn) + 1].val = val;
                // lazy[(2 * tn) + 1].type = type_of_update;
            }
        }
        return;
    }

    ll mid = (s + e) / 2;

    update(mid + 1, e, (2 * tn) + 1, l, r, val, type_of_update);
    update(s, mid, 2 * tn, l, r, val, type_of_update);

    treee[tn] = treee[2 * tn] + treee[(2 * tn) + 1];
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    forn(i, n)
    {
        cin >> arr[i];
    }
    build(0, n - 1, 1);
    // dbg(query(arr, treee, 0, n - 1, 1, 0, n - 1, lazy));
    // update(arr, treee, 0, n - 1, 1, 0, n - 1, 1, lazy, 2);
    // update(arr, treee, 0, n - 1, 1, 3, n - 1, 2, lazy, 1);
    // update(arr, treee, 0, n - 1, 1, 0, n - 1, 1, lazy, 2);
    // dbg(query(arr, treee, 0, n - 1, 1, 0, n - 1, lazy));
    forn(i, 10)
    {
        ll type;
        cin >> type;
        if (type == 3)
        {
            ll a, b;
            cin >> a >> b;
            a--, b--;
            dbg(query(0, n - 1, 1, a, b));
        }
        else if (type == 2)
        {
            ll a, b, x;
            cin >> a >> b >> x;
            a--, b--;
            update(0, n - 1, 1, a, b, x, 2);
        }
        else
        {
            ll a, b, x;
            cin >> a >> b >> x;
            a--, b--;
            update(0, n - 1, 1, a, b, x, 1);
        }
    }
}

int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
      freopen("revegetate.in", "r", stdin);
     freopen("in100.out", "w", stdout);
    // #endif
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
