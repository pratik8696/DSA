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
    int n, sx, sy, first = 0, second = 0, third = 0, fourth = 0, up = 0, left = 0, right = 0, down = 0;
    cin >> n >> sx >> sy;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        x = x - sx;
        y = y - sy;
        if (x > 0 && y > 0)
        {
            first++;
        }
        else if (x < 0 && y > 0)
        {
            second++;
        }
        else if (x > 0 && y < 0)
        {
            fourth++;
        }
        else if (x < 0 && y < 0)
        {
            third++;
        }
        else if (x == 0 && y > 0)
        {
            up++;
        }
        else if (x == 0 & y < 0)
        {
            down++;
        }
        else if (x > 0 && y == 0)
        {
            right++;
        }
        else if (x < 0 && y == 0)
        {
            left++;
        }
    }
    int arr[4], maxi = 0;
    arr[0] = up + first + second;
    arr[1] = right + first + fourth;
    arr[2] = down + third + fourth;
    arr[3] = left + second + third;
    forn(i, 4)
    {
        // cout<<arr[i]<<" ";
        maxi = max(maxi, arr[i]);
    }
    forn(i, 4)
    {
        if (arr[i] == maxi)
        {
            if (i == 0)
            {
                cout << arr[0] << ln;
                cout << sx << " " << sy + 1 << ln;
            }
            if (i == 1)
            {
                cout << arr[1] << ln;
                cout << sx + 1 << " " << sy << ln;
            }
            if (i == 2)
            {
                cout << arr[2] << ln;
                cout << sx << " " << sy - 1 << ln;
            }
            if (i == 3)
            {
                cout << arr[3] << ln;
                cout << sx - 1 << " " << sy << ln;
            }
            break;
        }
    }
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