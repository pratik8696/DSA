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
#define maxi 100001
ll arr[maxi], curr[maxi];
ll n, money, lastmoney;

bool isvalid(ll count)
{
    forn(i, n)
    {
        arr[i] = arr[i] + (i + 1) * count;
    }
    sort(al(arr, n));
    ll sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += arr[i];
    }
    if (sum <= money)
    {
        lastmoney = sum;
        return true;
    }
    return false;
}

void solve()
{
    cin >> n >> money;
    forn(i, n)
    {
        cin >> arr[i];
        curr[i] = arr[i];
    }
    ll i = 0, j = n, ans = 0;
    while (i <= j)
    {
        ll mid = (i + j) / 2;
        forn(k, n)
        {
            arr[k] = curr[k];
        }
        if (isvalid(mid))
        {
            ans = mid;
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    cout << ans << " " << lastmoney << ln;
}

int main()
{
    fast_cin();
    // ll t;
    // cin >> t;
    // for (int it = 1; it <= t; it++)
    // {
    solve();
    // }
    return 0;
}