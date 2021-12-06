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
typedef long long ll;
typedef unsigned long long int ull;
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
#define forn(i, n) for (ll i = 0; i < n; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) (arr), (arr) + (n)
#define sz(x) ((ll)(x).size())

// function for prime factorization
bool isvalid(int a, int b)
{
    string p = to_string(a);
    string q = to_string(b);
    if (p.length() != q.length())
    {
        return false;
    }
    int count = 0;
    forn(i,p.length())
    {
        if(p[i]!=q[i])
        {
            count++;
        }
    }
    if(count==1)
    {
        return true;
    }
    return false;
}

// function for sieve
#define max 10001
bool ar[max];
vector<ll> prime;
void sieve()
{
    ll i;
    fill(ar, ar + max, true);
    ar[0] = false;
    ar[1] = false;
    for (i = 0; i * i < max; i++)
    {
        if (ar[i] == true)
        {
            prime.pb(i);
            for (ll j = i * i; j < max; j += i)
            {
                ar[j] = false;
            }
        }
    }
    for (ll k = i; k < max; k++)
    {
        if (ar[k] == true)
        {
            prime.pb(k);
        }
    }
}

#define maxi 10001
vector<int> arr[maxi];
int vis[maxi];
int dist[maxi] = {-1};

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    dist[v] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto child : arr[curr])
        {
            if (vis[child] == 0)
            {
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
            }
        }
    }
}

vector<pair<int,int>> valid;
void creategraph()
{
    for (int i = 0; i < prime.size(); i++)
    {
        for (int j = 0; j < prime.size(); j++)
        {
            int a = prime[i];
            int b = prime[j];
            if (isvalid(a, b))
            {
                valid.pb(mp(a,b));
            }
        }
    }
    // creating a graph
    for(auto t:valid)
    {
        arr[t.first].pb(t.second);
        arr[t.second].pb(t.first);
    }
}

void solve()
{
    int a, b;
    cin >> a >> b;
    bfs(a);
    cout<<dist[b]<<ln;
}
int main()
{
    fast_cin();
    sieve();
    creategraph();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        for (int i = 0; i < maxi; i++)
        {
            fill(all(arr[i]), 0);
        }
        fill(al(vis, maxi), 0);
        fill(al(dist, maxi), 0);
        solve();
    }
    return 0;
}
