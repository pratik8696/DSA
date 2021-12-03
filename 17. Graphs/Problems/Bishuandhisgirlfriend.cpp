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

void dfs(int v,int dis,int dist[],int vis[],vector<int> arr[])
{
    vis[v]=1;
    dist[v]=dis;
    for (int i = 0; i < arr[v].size(); i++)
    {
        int child=arr[v][i];
        if(vis[child]==0)
        {
            dfs(child,dis+1,dist,vis,arr);
        }
    }
}

void solve()
{
    int dis=0;
    int n, m;
    cin >> n;
    m = n - 1;
    int vis[n+1];
    int dist[n+1];
    fill(al(vis,n+1),0);
    fill(al(dist, n + 1), 0);
    vector<int> arr[n + 1];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    int q;
    cin>>q;
    int girl[n+1];
    fill(al(girl,n+1),0);
    while(q--)
    {
        int a;
        cin>>a;
        girl[a]=1;
    }
    // dfs
    dfs(1,dis,dist,vis,arr);

    for(int i=1;i<n+1;i++)
    {
        if(girl[i]==1)
        {
            cout<<i<<ln;
            break;
        }
    }
}
// for (int i = 1; i < n+1; i++)
// {
//     cout<<i<<"-->";
//     for (auto t:arr[i])
//     {
//         cout<<t<<" ";
//     }
//     cout<<ln;
// }
// for (int i = 1; i < n+1; i++)
// {
//     cout<<vis[i]<<" ";
// }
// cout<<ln;
// for (int i = 1; i < n + 1; i++)
// {
//     cout << dist[i] << " ";
// }
// cout << ln;
// for (int i = 1; i < n + 1; i++)
// {
//     cout << girl[i] << " ";
// }
// cout << ln;

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