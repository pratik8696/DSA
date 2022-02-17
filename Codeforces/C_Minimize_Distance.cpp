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
    ll n, bag;
    cin >> n >> bag;
    ll arr[n];
    v64 pos, neg;
    forn(i, n)
    {
        cin >> arr[i];
        if (arr[i] > 0)
        {
            pos.pb(arr[i]);
        }
        else
        {
            neg.pb(abs(arr[i]));
        }
    }
    sort(all(pos));
    sort(all(neg));
    ll prev = 0, k = bag, sum = 0;
    if (pos.size() > 0)
    {
        for (ll i = 0; i < pos.size(); i++)
        {
            ll curr = pos[i];
            if (k > 0)
            {
                sum += curr - prev;
                k--;
            }
            if (k == 0 && i != pos.size() - 1)
            {
                sum += 2 * prev;
                k = bag;
            }
            prev = curr;
        }
    }
    cout << neg.size() << ln;
    // if (neg.size() > 0 && pos.size() > 0)
    // {
    //     sum += pos[pos.size() - 1];
    //     ll pp = 0, kk = bag;
    //     for (ll i = 0; i < neg.size(); i++)
    //     {
    //         ll curr = neg[i];
    //         if (kk > 0)
    //         {
    //             sum += curr - pp;
    //             kk--;
    //         }
    //         if (kk == 0&&i!=neg.size()-1)
    //         {
    //             sum += 2 * pp;
    //             kk = bag;
    //         }
    //         pp = curr;
    //     }
    // }

    // if (neg.size() > 0 && pos.size() == 0)
    // {
    //     ll pp = 0, kk = bag;
    //     for (ll i = 0; i < neg.size(); i++)
    //     {
    //         ll curr = neg[i];
    //         if (kk > 0)
    //         {
    //             sum += curr - pp;
    //             kk--;
    //         }
    //         if (kk == 0&&i!=neg.size()-1)
    //         {
    //             sum += 2 * pp;
    //             kk = bag;
    //         }
    //         pp = curr;
    //     }
    // }

    cout << sum << ln;
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