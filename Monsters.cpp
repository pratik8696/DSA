#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef long long ll;
// use less_equal to make it multiset
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef unsigned long long ull;
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
typedef vector<pair<p64, ll>> vpp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef multiset<ll> ms64;
typedef multiset<p64> msp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef priority_queue<ll> pq64;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define ie insert
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

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    return true;
}

void bfson2dformonsters(vp64 &monsters, vector<vector<char>> &arr, vv64 &dist)
{
    queue<pair<int, int>> q;
    vv64 vis(n + 10, v64(m + 10, 0));
    for (auto t : monsters)
    {
        vis[t.fi][t.se] = 1;
        dist[t.fi][t.se] = 1;
        q.push(mp(t.fi, t.se));
    }
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = currx + dx[i];
            int y1 = curry + dy[i];
            if (isvalid(currx + dx[i], curry + dy[i]) && vis[x1][y1] == 0 && arr[x1][y1] != '#')
            {
                dist[x1][y1] = dist[currx][curry] + 1;
                vis[x1][y1] = 1;
                q.push(mp(x1, y1));
            }
        }
    }
}

bool isvalidpeople(int x, int y, vv64 &dist, int time)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    if (time >= dist[x][y])
    {
        return false;
    }
    return true;
}

void bfson2dpeople(int x, int y, vector<vector<char>> &arr, vv64 &dist, vv64 &mondist, map<p64, p64> &path)
{
    queue<pair<int, int>> q;
    vv64 vis(n + 10, v64(m + 10, 0));
    vis[x][y] = 1;
    dist[x][y] = 1;
    q.push(mp(x, y));
    path[{x, y}] = {x, y};
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = currx + dx[i];
            int y1 = curry + dy[i];
            if (isvalidpeople(currx + dx[i], curry + dy[i], mondist, dist[currx][curry] + 1) && arr[x1][y1] != '#' && vis[x1][y1] == 0)
            {
                path[{x1, y1}] = {currx, curry};
                dist[x1][y1] = dist[currx][curry] + 1;
                vis[x1][y1] = 1;
                q.push(mp(x1, y1));
            }
        }
    }
}

char action(p64 prev, p64 next)
{
    ll x1 = prev.fi, y1 = prev.se;
    ll x2 = next.fi, y2 = next.se;
    if (y2 - y1 < 0)
    {
        return 'L';
    }
    if (y2 - y1 > 0)
    {
        return 'R';
    }
    if (x2 - x1 > 0)
    {
        return 'D';
    }
    return 'U';
}

void solve()
{
    cin >> n >> m;
    vector<vector<char>> arr(n + 10, vector<char>(m + 10, '#'));
    vv64 dist(n + 10, v64(m + 10, INF));
    vv64 person(n + 10, v64(m + 10, 0));
    vp64 monsters;
    map<p64, p64> path;
    ll sx = 0, sy = 0;
    forsn(i, 1, n + 1)
    {
        forsn(j, 1, m + 1)
        {
            char c;
            cin >> c;
            arr[i][j] = c;
            if (arr[i][j] == 'M')
            {
                monsters.pb({i, j});
            }
            if (arr[i][j] == 'A')
            {
                sx = i, sy = j;
            }
        }
    }

    bfson2dformonsters(monsters, arr, dist);
    bfson2dpeople(sx, sy, arr, person, dist, path);
    // lets check all the rows

    ll ex = INF, ey = INF;
    forsn(i, 1, n + 1)
    {
        forsn(j, 1, m + 1)
        {
            if (person[i][j] != 0 && i == 1)
            {
                ex = i, ey = j;
                break;
            }
            if (person[i][j] != 0 && i == n)
            {
                ex = i, ey = j;
                break;
            }
            if (person[i][j] != 0 && j == 1)
            {
                ex = i, ey = j;
                break;
            }
            if (person[i][j] != 0 && j == m)
            {
                ex = i, ey = j;
                break;
            }
        }
        if (ex != INF)
        {
            break;
        }
    }
    // cout << arr[ex][ey] << ln;
    // cout << ex << " " << ey << ln;
    if (ex == INF)
    {
        cout << "NO" << ln;
        return;
    }

    cout << "YES" << ln;
    p64 prev = {ex, ey};
    p64 source = {sx, sy};
    string s = "";
    vp64 res;
    while (prev != source)
    {
        res.pb(prev);
        prev = path[prev];
    }
    res.pb(prev);
    reverse(all(res));
    forn(i, res.size() - 1)
    {
        s.pb(action(res[i], res[i + 1]));
    }
    cout << s.length() << ln;
    cout << s << ln;
}

int main()
{
    fast_cin();
    //#ifndef ONLINE_JUDGE
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    //#endif
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
