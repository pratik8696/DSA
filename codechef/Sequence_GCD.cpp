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

v64 di;
void divisors(ll x)
{
    for (ll i = 1; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            if (x / i == i)
            {
                di.pb(x / i);
            }
            else
            {
                di.pb(x / i), di.pb(i);
            }
        }
    }
}

void solve()
{
    ll n, target_sum, x, sum = 0;
    cin >> n >> target_sum;
    v64 arr;
    forn(i, n)
    {
        cin >> x;
        arr.pb(x), sum += x;
    }
    ll divi = sum - target_sum;
    // if (divi <= n && divi != 0)
    // {
    //     cout << 1 << ln;
    //     return;
    // }
    if (divi == 0)
    {
        cout << 0 << ln;
        return;
    }
    divisors(divi);
    sort(all(di), greater<ll>());
    for (auto t : di)
    {
        // cout << t << ln;
        ll diff_sum = 0, count = 0, total_sum = 0;
        for (ll i = 0; i < n; i++)
        {
            ll nearest_term = (arr[i] / t) * t;
            if (nearest_term == 0)
            {
                count++;
            }
            diff_sum += arr[i] - nearest_term;
            total_sum += nearest_term;
            // cout << nearest_term << " ";
        }
        // cout << ln;
        // now remaining total sum after subtracting
        total_sum = total_sum - ((n - count) * t);
        // cout << total_sum << " " << diff_sum << ln;
        if (diff_sum > target_sum)
        {
            continue;
        }
        else
        {
            ll jobachahuahai = target_sum - diff_sum;
            if (jobachahuahai % t == 0 && total_sum % t == 0 && jobachahuahai <= total_sum)
            {
                cout << t << ln;
                break;
            }
        }
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
        di.clear();
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
