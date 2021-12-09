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

struct val
{
    ll pisa;
    ll idx;
    ll totalpisa;
};

val arr[100001];
bool compare(val a, val b)
{
    return a.totalpisa < b.totalpisa;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int v[n];
    forn(i, n)
    {
        cin >> arr[i].pisa;
        arr[i].idx = i + 1;
        arr[i].totalpisa = arr[i].pisa + n * (i + 1);
    }
    sort(al(arr, n), compare);
    forn(i, n)
    {
        cout << arr[i].pisa << " ";
    }
    cout << ln;
    forn(i, n)
    {
        cout << arr[i].idx << " ";
    }
    cout << ln;
    forn(i, n)
    {
        cout << arr[i].totalpisa << " ";
    }
    cout << ln;
    ll basesum = 0, multiplier = 0, t = 0, totalsum = 0,count=0;
    for (int i = 0; i < n; i++)
    {
        totalsum = basesum + (t * multiplier);
        if ((basesum + arr[i].pisa + ((t + 1) * (multiplier + arr[i].idx))) <= k)
        {
            count++;
            basesum += arr[i].pisa;
            t++;
            multiplier += arr[i].idx;
        }
        // cout << basesum << " " << t << " " << multiplier << " " << totalsum << ln;
    }
    totalsum = basesum + (t * multiplier);
    cout<<count<<" "<<totalsum<<ln;
}
int main()
{
    fast_cin();
    //  ll t;
    //  cin >> t;
    //  for(int it=1;it<=t;it++) {
    solve();
    //  }
    return 0;
}