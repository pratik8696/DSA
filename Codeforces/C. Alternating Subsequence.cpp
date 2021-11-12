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
    int n;
    cin >> n;
    ll arr[n];
    set<ll> s1;
    set<ll> s2;
    vector<ll> v;
    int flagneg = 1, flagpos = 1;
    forn(i, n)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            flagneg = 0;
        }
        if(arr[i]>=0)
        {
            flagpos = 0;
        }
    }
    if (flagneg == 0 && flagpos == 0)
    {
        forn(i, n)
        {
            if (arr[i] < 0)
            {
                s1.insert(-1*arr[i]);
                if (s2.size() > 0)
                {
                    auto it = s2.begin();
                    v.pb(-1 * (*it));
                    s2.clear();
                }
            }
            else
            {
                s2.insert(-1*arr[i]);
                if (s1.size() > 0)
                {
                    auto it = s1.begin();
                    v.pb(-1 * (*it));
                    s1.clear();
                }
            }
        }
        if (s1.size() > 0)
        {
            auto it = s1.begin();
            v.pb(-1 * (*it));
        }
        if (s2.size() > 0)
        {
            auto it = s2.begin();
            v.pb(-1 * (*it));
        }
        ll summ=0;
        for (auto it : v)
        {
            summ=summ+it;
            // cout << it << " "<<summ<<ln;
        }
        // cout << ln;
        cout << summ << endl;
    }
    else
    {
        ll maxi = INT_MIN;
        forn(i, n)
        {
            maxi = max(maxi, arr[i]);
        }
        cout << maxi << endl;
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