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

int timer = 1;
void dfs(int v,int vis[],int in[],int out[],vector<int> arr[])
{
    vis[v] = 1;
    in[v] = timer++;
    for (auto child : arr[v])
    {
        if (vis[child] == 0)
        {
            dfs(child,vis,in,out,arr);
        }
    }
    out[v] = timer++;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr[n+1];
    int vis[n+1];
    int in[n + 1];
    int out[n + 1];
    fill(al(vis,n+1),0);
    fill(al(in, n + 1), 0);
    fill(al(out, n + 1), 0);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        arr[b].pb(a);
        arr[a].pb(b);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<"-->";
    //     for(auto t:arr[i])
    //     {
    //         cout<<t<<" ";
    //     }
    //     cout<<ln;
    // }
    dfs(1,vis,in,out,arr);
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(in[a]<in[b]&&out[a]>out[b])
        {
            cout<<"YES"<<ln;
        }
        else{
            cout<<"NO"<<ln;
        }
    }
    // for (auto t : in)
    // {
    //     cout << t << " ";
    // }
    // cout << ln;
    // for (auto t : out)
    // {
    //     cout << t << " ";
    // }
    // cout << ln;
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
