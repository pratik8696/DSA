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
#define maxi 18
#define maxxx 200001
ll solution = INT_MIN;
ll arr[maxi][maxxx];
// #define maxxx 200011
vector<ll> v;

void create()
{
    for (ll i = 1; i < maxxx; i++)
    {
        if ((i & (i - 1)) == 0)
            v.push_back(i);
    }
    // for (ll i = 1; i <= 200000; i++)
    // {
    //     if ((i & (i - 1)) == 0)
    //         v.push_back(i);
    // }
    for (ll i = 0; i < 18; i++)
    {
        for (ll j = 1; j < maxxx; j++)
        {
            if ((v[i] & j) != 0)
            {
                arr[i][j] = 1 + arr[i][j - 1];
            }
            else
                arr[i][j] = arr[i][j - 1];
        }
    }
}

void solve()
{
    ll lower, upper;
    cin >> lower >> upper;
    ll size = upper - lower + 1;
    for (ll i = 0; i < 18; i++)
    {
        solution = max(solution, (arr[i][upper] - arr[i][lower - 1]));
    }
    // for (ll i = 0; i < 18; i++)
    // {
    //     solution = max(solution, (array[i][upper] - array[i][lower - 1]));
    // }
    cout << size - solution << endl;
}
int main()
{
    fast_cin();
    create();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solution = INT_MIN;
        solve();
    }
    return 0;
}