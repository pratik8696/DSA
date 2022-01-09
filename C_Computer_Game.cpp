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

ll k, n, a, b;
ll k1, n1, a1, b1;
ll rmove;

void refresh()
{
    k = k1, n = n1, a = a1, b = b1;
}

bool isvalid(ll movesbya)
{
    rmove = 0;
    ll mini = min(a, b);
    k = k - movesbya * a;
    if (k <= a)
    {
        movesbya--;
        k += a;
    }

    if (k > mini)
    {
        rmove = k / mini;
        k = k - rmove * mini;
        if (k <= mini)
        {
            rmove--;
            k += mini;
        }
    }
    // cout << rmove << " h h " << ln;

    if (rmove + movesbya >= n)
    {
        return true;
    }
    return false;
}

void solve()
{
    cin >> k >> n >> a >> b;
    k1 = k, n1 = n, a1 = a, b1 = b;
    // first check if win is possible
    ll mini = min(a, b);
    ll steps = k / mini;

    k = k - mini * (k / mini);
    if (k <= mini)
    {
        steps--;
        k += mini;
    }

    refresh();
    if (steps >= n)
    {
        // go for binary search
        // now max possible no of moves
        ll rmoves;
        ll maxmove = k / a;
        ll i = 0, j = maxmove, ans = 0;
        while (i <= j)
        {
            refresh();
            ll mid = (i + j) / 2;
            if (isvalid(mid))
            {
                j = mid - 1;
                if (mid > ans)
                {
                    ans = mid;
                    rmoves = rmove;
                }
            }
            else
            {
                i = mid + 1;
            }
        }
        cout << ans << " " << rmoves << ln;
        cout << ans + rmoves << ln;
    }
    else
    {
        cout << -1 << ln;
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
