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
#define maxi 1001
int arr[maxi][maxi];
int vis[maxi][maxi];
int dist[maxi][maxi];
int n, m;
int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

bool isvalid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] == 1)
    {
        return false;
    }
    return true;
}

void bfson2d(int x, int y)
{
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    dist[x][y] = 0;
    q.push(mp(x, y));
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            if (isvalid(currx + dx[i], curry + dy[i]))
            {
                int x1 = currx + dx[i];
                int y1 = curry + dy[i];
                dist[x1][y1] = dist[currx][curry] + 1;
                vis[x1][y1] = 1;
                q.push(mp(x1, y1));
            }
        }
    }
}

void solve()
{
    n = 8, m = 8;
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1 == r2 && c1 == c2)
    {
        cout << 0 << " ";
    }
    else if (r1 == r2 || c1 == c2)
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 2 << " ";
    }
    if (r1 == r2 && c1 == c2)
    {
        cout << 0 << " ";
    }
    else if ((r1 + c1) % 2 != (r2 + c2) % 2)
    {
        cout << 0 << " ";
    }
    else if (abs(r1 - r2) == abs(c1 - c2))
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 2 << " ";
    }
    bfson2d(r1, c1);
    cout << dist[r2][c2] << ln;
}
int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
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
