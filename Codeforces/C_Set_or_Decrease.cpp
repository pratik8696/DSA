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
#define maxi 200010
ll n, k;
ll arr[maxi], sum = 0, brr[maxi];

ll isvalid(ll mid)
{
    ll minsteps = INT_MAX;
    ll org = arr[0], tsum = sum, j = n - 1;
    ll steps = 0;
    steps += org - mid;
    tsum += -org + mid;
    if (tsum <= k)
    {
        return steps;
    }
    // cout << tsum << " " << steps << " " << i << ln;
    while (tsum >= k && j >= 0)
    {
        ll ae = arr[j--];
        tsum = tsum - ae + mid;
        steps++;
        // cout << tsum << " " << steps << " " << ae << " " << i << ln;
    }
    if (tsum <= k)
    {
        // cout << tsum << " " << k << ln;
        minsteps = min(steps, minsteps);
        return minsteps;
    }
    return INT_MAX;
    // cout << steps << ln;
}

void solve()
{

    cin >> n >> k;

    forn(i, n)
    {
        cin >> arr[i];
        brr[i] = arr[i];
        sum += arr[i];
    }

    if (sum <= k)
    {
        cout << 0 << ln;
        return;
    }

    if (n == 1)
    {
        if (arr[0] > k)
        {
            cout << abs(k - arr[0]) << ln;
            return;
        }
    }

    sort(al(arr, n));
    // ll steps = 0;
    // ll ttsum = sum;
    // if (1)
    // {
    //     ll i = 0, j = n - 1;
    //     while (ttsum > k && j >= 0)
    //     {
    //         ttsum = ttsum - arr[j] + arr[i];
    //         j--;
    //         steps++;
    //     }
    //     // cout << steps << endl;
    // }
    ll minans = INT_MAX;

    if (1)
    {
        ll i = INT_MIN, j = arr[0], ans;
        while (i <= j)
        {
            ll mid = (i + j) / 2;
            ans = isvalid(mid);
            // cout << ans << ln;
            if (ans < minans)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
            minans = min(ans, minans);
        }
        cout << minans << ln;
    }
    // cout << min(minans, steps) << ln;
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        n = 0, k = 0, sum = 0;
        for (int i = 0; i < maxi; i++)
        {
            arr[i] = 0;
            brr[i] = 0;
        }

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
