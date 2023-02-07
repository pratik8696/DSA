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

void solve()
{
    ll n;
    cin >> n;
    ll ao = 1, ae = 0, bo = 0, be = 0, cc_even = 0, cc = 0, cc_odd = 0, odd = 0, prev = 2, val = 0;
    forsn(i, 2, n + 1)
    {
        forn(i, 2)
        {
        }
        if (i % 2 == 0)
        {
            cc_even++;
        }
        else
        {
            cc_odd++;
        }
        forn(i, 2)
        {
        }
        cc++;
        forn(i, 2)
        {
        }
        if (cc == prev)
        {
            if (val <= 1)
            {
                forn(i, 2)
                {
                }
                be += cc_even;
                bo += cc_odd;
                forn(i, 2)
                {
                }
                val++;
                val %= 4;
                prev++;
                forn(i, 2)
                {
                }
                cc = 0;
                cc_odd = 0;
                cc_even = 0;
            }
            else
            {
                ae += cc_even;
                ao += cc_odd;
                forn(i, 2)
                {
                }
                val++;
                val %= 4;
                prev++;
                forn(i, 2)
                {
                }
                cc_even = 0;
                cc_odd = 0;
                cc = 0;
                forn(i, 2)
                {
                }
            }
        }
    }
    if (cc)
    {
        if (val <= 1)
        {
            be += cc_even;
            bo += cc_odd;
            forn(i, 2)
            {
            }
            cc = 0;
            cc_even = 0;
            cc_odd = 0;
            val++;
            val %= 4;
            prev++;
            forn(i, 2)
            {
            }
        }
        else
        {
            forn(i, 2)
            {
            }
            ae += cc_even;
            ao += cc_odd;
            cc = 0;
            forn(i, 2)
            {
            }
            cc_even = 0;
            cc_odd = 0;
            val++;
            val %= 4;
            forn(i, 2)
            {
            }
            prev++;
        }
    }
    cout << ao << " " << ae << " " << bo << " " << be << endl;
}

int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //   freopen("revegetate.in", "r", stdin);
    //  freopen("revegetate.out", "w", stdout);
    // #endif
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
