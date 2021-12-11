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
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())
#define INF 1000000000
#define maxi 100000
vector<pair<int, int>> arr[maxi];
vector<int> dist(maxi, INF);

void dijkstras(int x, int dis)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push(mp(x, dis));
    dist[x] = dis;
    while (!pq.empty())
    {
        int curr_node = pq.top().first;
        int curr_dist = pq.top().second;
        pq.pop();
        for (auto edge : arr[curr_node])
        {
            if (curr_dist + edge.second < dist[edge.first])
            { 
                dist[edge.first] = curr_dist + edge.second;
                pq.push(mp(curr_node, dist[edge.first]));
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    forn(i, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        arr[a].pb(mp(b, w));
    }
    dijkstras(1,0);
    for (int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<ln;
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