#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())

bool compare(p64 a, p64 b)
{
    return a.second < b.second;
}

void solve()
{
    ll n, l, k;
    cin >> n >> l >> k;
    ll arr[n], brr[n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    forn(i, n)
    {
        cin >> brr[i];
    }
    vp64 v, o;
    if (k == 0)
    {
        ll result = 0;
        for (ll i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                result += (l - arr[i]) * brr[i];
            }
            else
            {
                result += (arr[i + 1] - arr[i]) * brr[i];
            }
        }
        cout << result << ln;
        return;
    }
    v.pb({arr[0], brr[0]});
    for (ll i = 1; i < n; i++)
    {
        o.pb({arr[i], brr[i]});
    }
    sort(all(o), compare);
    for (ll i = 0; i < o.size(); i++)
    {
        if (v[v.size() - 1].second > o[i].second)
        {
            v.pb({o[i].fi, o[i].se});
        }
    }
    v.pb({l, 0});
    sort(all(v));
    ll time = 0;
    for (ll i = 0; i < v.size() - 1; i++)
    {
        time += v[i].second * (v[i + 1].first - v[i].first);
    }
    cout << time << ln;
}
int main()
{
    fast_cin();
    ll t = 1;
    //  cin >> t;
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
