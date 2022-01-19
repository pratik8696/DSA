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
char arr[maxi][maxi];
ll t[maxi][maxi];
ll n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vp64 monsters, start;
map<p64, p64> par_mp;

bool isvalid(int x, int y, int timer)
{
    if (x < 1 || x > n || y < 1 || y > m || arr[x][y] == '#' || t[x][y] <= timer)
    {
        return false;
    }
    return true;
}

bool isescape(int x, int y, int timer)
{
    if (isvalid(x, y, timer))
    {
        if (x == 1 || y == 1 || x == n || y == m)
        {
            return true;
        }
    }
    return false;
}

void pre()
{
    queue<pair<p64, ll>> q;
    for (auto mm : monsters)
    {
        q.push({mm, 0});
    }
    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = cx + dx[i];
            int ty = cy + dy[i];
            if (isvalid(tx, ty, timer))
            {
                t[tx][ty] = timer;
                q.push({{tx, ty}, timer});
            }
        }
    }
}

bool escape()
{
    queue<pair<p64, ll>> q;
    q.push(mp(start[0], 0));
    par_mp[start[0]] = {-1, -1};
    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = cx + dx[i];
            int ty = cy + dy[i];
            if (isescape(tx, ty, timer))
            {
                par_mp[{tx, ty}] = {cx, cy};
                start.pb(mp(tx, ty));
                return true;
            }
            if (isvalid(tx, ty, timer))
            {
                par_mp[{tx, ty}] = {cx, cy};
                t[tx][ty] = timer;
                q.push({{tx, ty}, timer});
            }
        }
    }
    return false;
}

string res = "";
void path(int tx, int ty, int time)
{
    if (time == 0 || tx == -1 && ty == -1)
    {
        return;
    }
    // cout << tx << " " << ty << ln;
    ll dirx = par_mp[{tx, ty}].first - tx;
    ll diry = par_mp[{tx, ty}].second - ty;
    if (dirx == -1 && diry == 0)
    {
        res.pb('D');
    }
    else if (dirx == 1 && diry == 0)
    {
        res.pb('U');
    }
    else if (dirx == 0 && diry == -1)
    {
        res.pb('R');
    }
    else
    {
        res.pb('L');
    }
    time--;
    path(par_mp[{tx, ty}].first, par_mp[{tx, ty}].second, time);
}

void solve()
{
    for (int i = 1; i < maxi; i++)
    {
        for (int j = 1; j < maxi; j++)
        {
            t[i][j] = INF;
        }
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'M')
            {
                monsters.pb(mp(i, j));
            }
            else if (arr[i][j] == 'A')
            {
                start.pb(mp(i, j));
            }
        }
    }
    pre();
    escape();
    // cout << par_mp.size() << ln;
    if (start.size() == 2)
    {
        path(start[1].fi, start[1].se, par_mp.size());
        reverse(all(res));
        cout << "YES" << ln;
        cout << res.length() - 1 << ln;
        for (int i = 1; i < res.length(); i++)
        {
            cout << res[i];
        }
        cout << ln;
    }
    else
    {
        cout << "NO" << ln;
    }
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
