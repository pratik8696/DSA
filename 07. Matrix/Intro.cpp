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

void solve()
{
    /*
    2darray array of array

    0--->0 1 2 3 4
    1--->0 1 2 3 4
    2--->0 1 2 3 4
    3--->0 1 2 3 4

    intitalization is like this
    int arr[n][m];

    at any point agr kuch access krna hai tmko usko
    row pta hona chahiye and column bhi

    00 01 02 03
    10 11 12 13
    20 21 22 23

    ab merkko agr koi element access krna hai then
    it's like this arr[1][2]

    i/o
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    1 2 3
    4 5 6
    7 8 9

    ab merko output krna hai

    o/p

     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    1 2 3
    4 5 6
    7 8 9

    for(0->3)
    {
        for(0->4)
        {
            0->0 1 2 3 4
            1->0 1 2 3 4
            2->0 1 2 3 4
            3->0 1 2 3 4
        }
    }

    00 01 02 03 04
    10 11 12 13 14
    20 21 22 23 24
    30 31 32 33 34

    00 10 20 30
    01 11 21 31
    02 12 22 32
    03 13 23 33
    04 14 24 34

    for(0->4(this is basically no of columns))
    {
        for(0->3(this is basically no of rows))
        {

        }
    }

    00 01 02 03 04
    10 11 12 13 14
    20 21 22 23 24
    30 31 32 33 34

    Golu Gaal Wali MOti billu

    */
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