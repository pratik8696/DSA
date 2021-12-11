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
#define alll(arr, n) (arr), (arr) + (n)
#define sz(x) ((ll)(x).size())
#define maxi 10000
vector<int> arr[maxi];
int vis[maxi];
int dist[maxi] = {-1};

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    dist[maxi] = 0;
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

vector<int> primes;
#define max 10000
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

bool isvalid(int x, int y)
{
    string a = to_string(x);
    string b = to_string(y);
    int count = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            count++;
        }
    }
    if (count == 1)
    {
        return true;
    }
    return false;
}

void creategraph()
{
    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = 0; j < primes.size(); j++)
        {
            int a = primes[i];
            int b = primes[j];
            if (isvalid(a, b))
            {
                arr[a].pb(b);
                arr[b].pb(a);
                // for (int k = 0; k < arr[a].size(); k++)
                // {
                //     cout << arr[a][k] << ln;
                // }
            }
        }
    }
}

void solve()
{
    int a, b;
    cin >> a >> b;
    bfs(a);
    cout << dist[b] << ln;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    sieve();
    for (auto t : prime)
    {
        if (t >= 1000 && t < 10000)
        {
            primes.pb(t);
        }
    }
    creategraph();
    for (int it = 1; it <= t; it++)
    {
        for (int i = 0; i < maxi; i++)
        {
            vis[i] = 0;
            dist[i] = 0;
        }
        solve();
    }
    return 0;
}