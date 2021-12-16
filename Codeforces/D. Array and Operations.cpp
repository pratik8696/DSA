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

bool compare(ll a, ll b)
{
    return a > b;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    sort(al(arr, n));
    ll sum = 0, actualstep = 0;
    int idx = 0, j;
    forn(i, n)
    {
        cout << arr[i] << " ";
    }
    cout << ln;
    for (int i = 0, step = 1; (step <= k); i++, step++)
    {
        if (arr[i] != 0)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] != 0)
                {
                    if (arr[j] > arr[i])
                    {
                        arr[j] = 0, arr[i] = 0;
                        break;
                    }
                }
                if (j == n - 1)
                {
                    for (int k = i + 1; k < n; k++)
                    {
                        if (arr[k] != 0)
                        {
                            sum += arr[i] / arr[k];
                            arr[i] = 0, arr[k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    forn(i, n)
    {
        sum += arr[i];
        cout << arr[i] << " ";
    }

    cout << ln;
    cout << sum << ln;
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