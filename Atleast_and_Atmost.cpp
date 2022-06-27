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
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
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
    ll n;
    cin >> n;
    ll arr[n];
    v64 pre(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll sum = 0;
    sort(al(arr, n));
    v64 ans2, ans1;
    for (ll i = 0; i < n; i++)
    {
        sum += arr[i];
        pre[i] = sum;
    }
    forn(i, n)
    {
        ll r1, r2;
        ll it = upper_bound(al(arr, n), i) - arr;
        ll ans = 0;
        if (it != n)
        {
            ans += n - it;
            if (it == 0)
            {
                ans += ((n * (n - it)) - (pre[n - 1]));
            }
            else
            {
                ans += ((n * (n - it)) - (pre[n - 1] - pre[it - 1]));
            }
        }
        if (1)
        {
            ll itt = lower_bound(al(arr, n), i) - arr;
            if (1)
            {
                if (arr[itt] >= i)
                {
                    itt--;
                }
            }
            if (1)
            {
                if (itt >= 0)
                {
                    ll r = (n * (itt + 1)) - pre[itt];
                    ans += r;
                }
            }
            ans2.pb(ans);
        }
    }
    vp64 res;
    ll ans = 0;
    forn(i, n)
    {
        ll r1, r2;
        ll it = upper_bound(al(arr, n), i) - arr;
        if (it != n)
        {
            ans += n - it;
        }
        if (1)
        {
            res.pb({ans, ans2[i]});
        }
        ans = 0;
    }
    for (auto t : res)
    {
        cout << t.fi << " " << t.se << ln;
    }
}

int main()
{
    fast_cin();
    //#ifndef ONLINE_JUDGE
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    //#endif
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
