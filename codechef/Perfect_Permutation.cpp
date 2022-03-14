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
typedef vector<ll> v64;
typedef vector<int> v32;
typedef unsigned long long ull;
typedef vector<p64> vp64;
typedef pair<double, double> pdd;
typedef vector<p32> vp32;
double eps = 1e-12;
#define se second

ll MOD = 1000000007;
#define fi first
#define INF 2e18
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n

#define ln "\n"
#define forn(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define sz(x) ((ll)(x).size())
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define dbg(x) cout << #x << " = " << x << ln
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define pb push_back



void solve()
{
    long long int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 1 << ln;
        return;
    }
    ll arr[n + 1];
    for (ll i = 1; i < n + 1; i++)
    {
        arr[i] = i;
    }

    for (ll i = k + 1; i <= n; i += 2)
    {
        if (i + 1 <= n)
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    if ((k % 2 == 0 && n % 2 == 0) || (k % 2 != 0 && n % 2 != 0))
    {
        for (ll i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        swap(arr[1], arr[n]);
        for (ll i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    cout << ln;

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
