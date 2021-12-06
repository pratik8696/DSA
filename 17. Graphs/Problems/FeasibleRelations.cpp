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
#define maxi 100001
vector<int> arr[maxi];
int vis[maxi];
int cc[maxi];
int curr;

void dfs(int v)
{
    vis[v]=1;
    cc[v]=curr;
    for(auto child:arr[v])
    {
        if(vis[child]==0)
        {
            dfs(child);
        }
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> rem;
    forn(i, k)
    {
        int a, b;
        string s;
        cin >> a >> s >> b;
        if (s == "!=")
        {
            rem.pb(mp(a, b));
        }
        else
        {
           arr[a].pb(b);
           arr[b].pb(a);
        }    
    }
    for (int i = 1; i <= n; i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            curr++;
        }
    }
    int flag=1;
    for (auto t:rem)
    {
        if(cc[t.first]==cc[t.second])
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        cout<<"YES"<<ln;
    }
    else{
        cout<<"NO"<<ln;
    }
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        for (int i = 0; i < maxi; i++)
        {
            fill(all(arr[i]),0);
        }
        fill(al(vis,maxi),0);
        fill(al(cc, maxi), 0);
        solve();
    }
    return 0;
}
