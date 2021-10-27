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

int foccur(int arr[], int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == key)
    {
        return 0;
    }
    int i = foccur(arr + 1, n - 1, key);
    if (i == -1)
    {
        return -1;
    }
    return i + 1;
}

int loccur(int arr[], int n, int k)
{
    static int len=n;
    if (n == 0)
    {
        return -1;
    }
    if (arr[n - 1] == k)
    {
        return 0;
    }
    int t = loccur(arr, n - 1, k);
    if (t == -1)
    {
        return -1;
    }
    else
    {
        if(n==len)
        {
            return n-t-1;
        }
        return t + 1;
    }
}

void pao(int arr[],int n,int k,int i)
{
    if(i==n)
    {
        return;
    }
    if(arr[i]==k)
    {
        cout<<i<<" ";
    }
    pao(arr,n,k,i+1);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    cout << loccur(arr, n, k)<<ln;
    cout << foccur(arr, n, k) << ln;
    pao(arr,n,k,0);
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
