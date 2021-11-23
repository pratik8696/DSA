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
    ll n;
    cin >> n;
    ll arr[n];
    forn(i, n)
    {
        arr[i] = i + 1;
        // cout << arr[i] << " ";
    }
    vector<ll> v;
    // cout << ln;

    if ((n + 1) % 4 == 0 || n % 4 == 0)
    {
        cout << 0 << ln;
        ll i = 0, j = 1, target = (n * (n + 1)) / 4, sum = arr[0];
        // cout << sum << " " << i << " " << j << " " << target << ln;
        while (i < j)
        {
            if (sum == target)
            {
                cout << j - i  << " ";
                for (ll h = i; h < j; h++)
                {
                    cout << arr[h] << " ";
                    v.pb(arr[h]);
                }
                break;
            }
            else if (sum > target)
            {
                sum = sum - arr[i];
                i++;
            }
            else if (sum < target)
            {
                sum = sum + arr[j];
                j++;
            }
            // cout << sum << " " << i << " " << j<<" "<<target << ln;
        }
    }
    else
    {
        cout << 1 << ln;
        ll i = 0, j = 1, target = ((n * (n + 1)) / 4), sum = arr[0];
        while (i < j)
        {
            if (sum == target||sum==(target+1))
            {
                cout << j - i  << " ";
                for (ll h = i; h < j; h++)
                {
                    cout << arr[h] << " ";
                    v.pb(arr[h]);
                }
                break;
            }
            else if (sum > target)
            {
                sum = sum - arr[i++];
            }
            else if (sum < target)
            {
                sum += arr[j++];
            }
        }
    }
}
int main()
{
    fast_cin();
    //  ll t;
    //  cin >> t;
    //  for(int it=1;it<=t;it++) {
    solve();
    //  }
    return 0;
}