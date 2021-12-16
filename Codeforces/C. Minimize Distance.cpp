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
    int n, store;
    cin >> n >> store;
    vector<int> arr, negarr;
    forn(i, n)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            arr.pb(x);
        }
        else
        {
            negarr.pb(abs(x));
        }
    }
    sort(all(arr));
    sort(all(negarr));
    int lastneg = 0, lastpos = 0;
    int currdist = 0, k = 0, totaldist = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (k == 0)
        {
            totaldist += 2 * currdist;
            k = store;
        }
        if (arr[i] != 0)
        {
            lastpos = arr[i];
            currdist = arr[i];
            arr[i] = 0;
            k--;
        }
        cout << currdist << " " << totaldist << " " << k << ln;
    }
    cout << currdist << " " << totaldist << " " << k << ln;
    if (arr.size() % store == 0)
    {
        // mtlb fir se wapas jakar ana pdega last point pr
        totaldist = totaldist + lastpos;
    }
    cout << currdist << " " << totaldist << " " << k << ln;
    // baki cases khud handle kar lega vmros
    int t = 0, currnegdist = 0, totalnegdistance = 0;
    if (negarr.size())
    {
        // wapas origin par aa gye
        totaldist += currdist;

        for (int i = 0; i < negarr.size(); i++)
        {
            if (t == 0)
            {
                totalnegdistance += 2 * currnegdist;
                t = store;
            }
            if (negarr[i] != 0)
            {
                currnegdist = negarr[i];
                negarr[i] = 0;
                t--;
            }
        }
        // cout << currnegdist << " " << totalnegdistance << " " << k << ln;
        if (negarr.size() % store == 0)
        {
            // mtlb fir se wapas jakar ana pdega last point pr
            totalnegdistance += lastpos;
        }
        // cout << currnegdist << " " << totalnegdistance << " " << k << ln;
        cout << totaldist + totalnegdistance << ln;
    }
    else
    {
        cout << totaldist << ln;
    }
    // cout << currdist << " " << totaldist << " " << k << ln;
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