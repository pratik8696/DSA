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

bool compare(ll a, ll b)
{
    return a > b;
}

void solve()
{
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, compare);
    ll i = 0, k = 1, sum = 0, count = 0;
    sum = arr[i];
    if (sum / k < x)
    {
        cout << 0 << endl;
        return;
    }
    // cout << "THE SUM IS " << double(sum) << " " << double(sum) / double(k) << endl;
    while (float(sum)/float(k) >= float(x) && i <= n-1)
    {
        i++;
        k++;
        sum += arr[i];
        // cout<<i<<" " << "THE SUM IS " << float(sum) << " " << float(sum) / float(k) << endl;
    }
    if(sum/k>=x)
    {
        if(k>n)
        {
            k=n;
        }
        cout<<k<<endl;
    }
    else{
        cout<<k-1<<endl;
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