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
/*
1 1 1 1
1 1 1 6
1 1 2 5
1 1 3 4
1 1 4 3
1 1 4 10
1 1 5 2
1 1 5 9
1 1 6 1
1 1 6 8
1 1 7 7
1 1 8 6
1 1 9 5
1 1 10 4
1 2 1 5
1 2 2 4
1 2 3 3
1 2 3 10
1 2 4 2
1 2 4 9
1 2 5 1
1 2 5 8
1 2 6 7
1 2 7 6
1 2 8 5
1 2 9 4
1 2 10 3
1 3 1 4
1 3 2 3
1 3 2 10
1 3 3 2
1 3 3 9
1 3 4 1
1 3 4 8
1 3 5 7
1 3 6 6
1 3 7 5
1 3 8 4
1 3 9 3
1 3 10 2
1 4 1 3
1 4 1 10
1 4 2 2
1 4 2 9
1 4 3 1
1 4 3 8
1 4 4 7
1 4 5 6
1 4 6 5
1 4 7 4
1 4 8 3
1 4 9 2
1 4 10 1
1 4 10 10
1 5 1 2
1 5 1 9
1 5 2 1
1 5 2 8
1 5 3 7
1 5 4 6
1 5 5 5
1 5 6 4
1 5 7 3
1 5 8 2
1 5 9 1
1 5 9 10
1 5 10 9
1 6 1 1
1 6 1 8
1 6 2 7
1 6 3 6
1 6 4 5
1 6 5 4
1 6 6 3
1 6 7 2
1 6 8 1
1 6 8 10
1 6 9 9
1 6 10 8
1 7 1 7
1 7 2 6
1 7 3 5
1 7 4 4
1 7 5 3
1 7 6 2
1 7 7 1
1 7 7 10
1 7 8 9
1 7 9 8
1 7 10 7
1 8 1 6
1 8 2 5
1 8 3 4
1 8 4 3
1 8 5 2
1 8 6 1
1 8 6 10
1 8 7 9
1 8 8 8
1 8 9 7
*/
void solve()
{
    int n;
    cin >> n;
    ll arr[n],sum=0;
    forn(i, n)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    ll finalsum=sum;
    for (int i = 0; i < n; i++)
    {
        if(sum-arr[i]<=finalsum/2)
        {
            cout<<i+1<<ln;
            return;
        }
        else{
            sum=sum-arr[i];
        }
        // cout<<sum<<ln;
    }
}
int main()
{
    fast_cin();
    ll t = 1;
    //  cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}