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
#define fast_cin()                    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                    
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())
#define maxi 1000
vector<int> arr[maxi];
int LCA[maxi][maxi];
int level[maxi];
int vis[maxi];
int n, m, maxn;

void dfs(int v, int par)
{
    LCA[v][0] = par;
    for (auto child : arr[v])
    {
        if (child != par)
        {
            dfs(child, v);
        }
    }
}

void bfs(int v)
{
    queue<int> q;
    vis[v] = 1;
    level[v] = 0;
    q.push(v);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto child : arr[curr])
        {
            if (vis[child] == 0)
            {
                level[child] = level[curr] + 1;
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}

void init()
{
    dfs(1, -1);
    for (int j = 1; j <= maxn; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (LCA[i][j - 1] != -1)
            {
                int par = LCA[i][j - 1];
                LCA[i][j] = LCA[par][j - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (level[a] > level[b])
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int d = level[b] - level[a];
    while (d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d = d - pow(2, i);
    }
    if (a == b)
    {
        return a;
    }
    while (LCA[a][0] != LCA[b][0])
    {
        a = LCA[a][0];
        b = LCA[b][0];
    }
    return LCA[a][0];
}

void solve()
{
    cin >> n >> m;
    maxn = log2(n);
    for (int i = 0; i < maxi; i++)
    {
        for (int j = 0; j < maxi; j++)
        {
            LCA[i][j] = -1;
        }
    }
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    bfs(1);
    init();
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << ln;
    }
}

int main()
{
    fast_cin();
    solve();
    return 0;
}