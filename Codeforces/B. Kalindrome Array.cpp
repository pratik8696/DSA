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

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    set<ll> s;
    forn(i, n)
    {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    if (n <= 2 || s.size() <= 2)
    {
        cout << "YES" << ln;
        return;
    }

    int f = 1;
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        if (arr[i] != arr[j])
        {
            f = 0;
        }
    }
    if (f == 1)
    {
        cout << "YES" << ln;
        return;
    }

    int one, two;
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        if (arr[i] != arr[j])
        {
            one = arr[i];
            two = arr[j];
            break;
        }
    }

    string p = "", q = "";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != one)
        {
            p.pb(arr[i]);
        }
        if (arr[i] != two)
        {
            q.pb(arr[i]);
        }
    }

    int flag1 = 1, flag2 = 1;
    for (int i = 0, j = p.length() - 1; i <= j; i++, j--)
    {
        if (p[i] != p[j])
        {
            flag1 = 0;
        }
    }

    for (int i = 0, j = q.length() - 1; i <= j; i++, j--)
    {
        if (q[i] != q[j])
        {
            flag2 = 0;
        }
    }

    if (flag1 == 1 || flag2 == 1)
    {
        cout << "YES" << ln;
    }
    else
    {
        cout << "NO" << ln;
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