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
#define maxi 100010
ll n;
ll arr[maxi], brr[maxi];

bool isvalid(ll extramatch)
{
    ll newmatches = n + extramatch;
    // cout << "Newmatches " << newmatches << ln;
    ll validity = newmatches - newmatches / 4;
    // cout << "validity " << validity << ln;
    ll sumofa = 0, sumofb = 0;
    for (int i = n - 1, valid = validity; i >= 0 && valid; i--, valid--)
    {
        sumofb = sumofb + brr[i];
        // cout << "Sumofb " << sumofb << ln;
    }
    // cout << "Sumofb " << sumofb << ln;
    sumofa = extramatch * 100;
    // cout << "Sumofa " << sumofa << ln;
    ll validityofa = validity - extramatch;
    for (int i = n - 1, valid = validityofa; i >= 0 && valid; i--, valid--)
    {
        sumofa += arr[i];
        // cout << "Sumofa " << sumofa << ln;
    }
    // cout << "Sumofa " << sumofa << ln;
    if (sumofa >= sumofb)
    {
        return true;
    }
    return false;
}

void solve()
{
    cin >> n;
    forn(i, n)
    {
        cin >> arr[i];
    }
    forn(i, n)
    {
        cin >> brr[i];
    }
    sort(al(arr, n));
    sort(al(brr, n));
    ll matches = n - n / 4, sumofa = 0, sumofb = 0;
    // forn(i, n)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << ln;
    // forn(i, n)
    // {
    //     cout << brr[i] << " ";
    // }
    // cout << ln;
    for (int i = n - 1, valid = matches; i >= 0 && matches; i--, valid--)
    {
        sumofa += arr[i];
        sumofb += brr[i];
    }
    // cout << sumofa << " " << sumofb << ln;
    // if (sumofa >= sumofb)
    // {
    //     cout << 0 << ln;
    //     return;
    // }
    // cout << isvalid(1) << ln;
    ll i = 0, j = INT_MAX, ans = INT_MAX;
    while (i <= j)
    {
        ll mid = (i + j) / 2;
        if (isvalid(mid))
        {
            j = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            i = mid + 1;
        }
    }
    cout << ans << ln;
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
