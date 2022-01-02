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
#define maxi 1010
char arr[maxi][maxi];
int vis[maxi][maxi];
char step[maxi][maxi];
int dist[maxi][maxi];
int n, m;
int a, b, c, d;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool isvalid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] == 1 || arr[x][y] == '#')
    {
        return false;
    }
    return true;
}

map<pair<ll, ll>, pair<ll, ll>> par;
void bfson2d(int x, int y)
{
    queue<pair<int, int>> q;
    step[x][y] = 'O';
    vis[x][y] = 1;
    dist[x][y] = 0;
    par[mp(x, y)] = mp(-1, -1);
    q.push(mp(x, y));
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (isvalid(currx + dx[i], curry + dy[i]))
            {
                int x1 = currx + dx[i];
                int y1 = curry + dy[i];
                par[mp(x1, y1)] = mp(currx, curry);
                if (i == 0)
                {
                    step[x1][y1] = 'U';
                }
                else if (i == 1)
                {
                    step[x1][y1] = 'R';
                }
                else if (i == 2)
                {
                    step[x1][y1] = 'D';
                }
                else if (i == 3)
                {
                    step[x1][y1] = 'L';
                }
                dist[x1][y1] = dist[currx][curry] + 1;
                vis[x1][y1] = 1;
                q.push(mp(x1, y1));
            }
        }
    }
}
ll kk = 0;
string ress = "";
void path(int x, int y)
{
    if (x == -1 && y == -1)
    {
        return;
    }
    ress.pb(step[x][y]);
    path(par[mp(x, y)].first, par[mp(x, y)].second);
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                a = i;
                b = j;
            }
            else if (arr[i][j] == 'B')
            {
                c = i;
                d = j;
            }
        }
    }
    bfson2d(a, b);

    if (vis[c][d] == 0)
    {
        cout << "NO" << ln;
        return;
    }
    path(c, d);
    cout << "YES" << ln;
    cout << dist[c][d] << ln;
    ress.pop_back();
    reverse(all(ress));
    cout << ress << ln;
    cout << ln;
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
