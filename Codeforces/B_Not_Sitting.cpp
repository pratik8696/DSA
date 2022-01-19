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
#define maxi 1001
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ull unsigned long long
using namespace std;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll a[n + 1][m + 1];
    map<ll, ll> mp;
    vector<ll> v;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            a[i][j] = (i + j);
            v.push_back(i + j);
        }
    }
    ll pren = n;
    ll prem = m;
    /* for(ll i=1;i<=pren/2;i++)
     { for(ll j=1;j<=prem/2;j++)
        { ll mx1=abs(a[i][j]-v[0]);
          ll mx2=abs(a[i][j]-v[v.size()-1]);
          ll mx3=max(mx1,mx2);
          mp[mx3]++;
        }

     }
     */
    sort(all(v));
    if (pren % 2 != 0)
        pren++;
    if (prem % 2 != 0)
        prem++;
    /* for(ll i=1;i<=pren/2;i++)
     { for(ll j=1;j<=prem/2;j++)
        { ll mx1=abs(a[i][j]-v[0]);
          ll mx2=abs(a[i][j]-v[v.size()-1]);
          ll mx3=max(mx1,mx2);
          mp[mx3]++;
        }

     }
     */
    for (ll i = 1; i <= pren / 2; i++)
    {
        for (ll j = m; j > prem / 2; j--)
        {
            a[i][j] = a[i][m + 1 - j];
        }
    }
    for (ll i = (n / 2) + 1; i <= n; i++)
    {
        for (ll j = 1; j <= prem; j++)
        {
            a[i][j] = a[n + 1 - i][j];
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            ll mx1 = abs(a[i][j] - v[0]);
            ll mx2 = abs(a[i][j] - v[v.size() - 1]);
            ll mx3 = max(mx1, mx2);
            mp[mx3]++;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
        for (ll i = 0; i < it->second; i++)
            cout << it->first << " ";
    cout << endl;
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

/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
*/
