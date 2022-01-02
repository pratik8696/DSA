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
#define maxi 110
map<int, vector<int>> arr;
// int vis[maxi];
vector<pair<int, int>> v;

int dfs(int v, int search, int par)
{
    for (auto child : arr[v])
    {
        if (par != child)
        {
            if (dfs(child, search, v) == 1)
            {
                return 1;
            }
        }
        if (search == child)
        {
            return 1;
        }
    }
    return -1;
}

void create(ll a, ll b)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (a < v[i].first && v[i].first < b)
        {
            arr[v[i].second].pb(a);
        }
        else if (a < v[i].second && v[i].second < b)
        {
            arr[v[i].second].pb(a);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (b < v[i].first && v[i].first < a)
        {
            arr[v[i].second].pb(b);
        }
        else if (b < v[i].second && v[i].second < a)
        {
            arr[v[i].second].pb(b);
        }
    }
}

void solve()
{
    ll option, a, b;
    cin >> option >> a >> b;
    if (option == 1)
    {
        v.pb(mp(a, b));
        arr[a].pb(b);
        create(a, b);
    }
    else if (option == 2)
    {
        if (dfs(a, b, -1) == 1)
        {
            cout << "YES" << ln;
            return;
        }
        else
        {
            cout << "NO" << ln;
            return;
        }
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
