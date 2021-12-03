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
    ll n;
    cin >> n;
    if (n % 25 == 0)
    {
        cout << 0 << ln;
        return;
    }
    string s = to_string(n);
    int five = 0, seven = 0, two = 0, zero = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            zero++;
        }
        else if (s[i] == '7')
        {
            seven++;
        }
        else if (s[i] == '5')
        {
            five++;
        }
        else if (s[i] == '2')
        {
            two++;
        }

        if (zero == 2)
        {
            cout << s.length() - i - 1 << ln;
            return;
        }
        else if (two == 1 && five >= 1)
        {
            cout << s.length() - i - 1 << ln;
            return;
        }
        else if (zero >= 1 && five == 1)
        {
            cout << s.length() - i - 1 << ln;
            return;
        }
        else if (seven == 1 && five >= 1)
        {
            cout << s.length() - i - 1 << ln;
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