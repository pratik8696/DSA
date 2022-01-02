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
5
3
6 6 1
1
9
6
1 1 1 2 2 2
2
8 6
6
6 2 3 4 5 1
*/
void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    ll even = 0, odd = 0;
    char e = '1', o = '0';
    string s = "";
    queue<ll> ee, oo,ooo;
    forn(i, n)
    {
        cin >> arr[i];
        if (arr[i] & 1)
        {
            oo.push(i);
            ooo.push(i);
            s.pb(o);
            odd++;
        }
        else
        {
            ee.push(i);
            s.pb(e);
            even++;
        }
    }
    // cout << s << ln;
    if (even - odd == 1)
    {
        // 10101
        ll sum = 0;
        string res = "";
        while (odd--)
        {
            res.pb('1');
            res.pb('0');
        }
        res.pb('1');
        // cout << res << ln;
        for (int i = 0; i < res.length(); i++)
        {
            if (res[i] == '1')
            {
                sum += abs(ee.front() - i);
                // cout << ee.front() << ln;
                ee.pop();
            }
        }
        cout << sum << ln;
        // cout << res << ln;
    }
    else if (odd - even == 1)
    {
        // 01010
        ll sum = 0;
        string res = "";
        while (even--)
        {
            res.pb('0');
            res.pb('1');
        }
        res.pb('0');
        for (int i = 0; i < res.length(); i++)
        {
            if (res[i] == '0')
            {
                sum += abs(oo.front() - i);
                oo.pop();
            }
        }
        cout << sum << ln;
        // cout << res << ln;
    }
    else if (even == odd)
    {
        ll sum = 0, sum2 = 0;
        string res = "", res2 = "";

        while (odd--)
        {
            res.pb('0');
            res.pb('1');
        }

        while (even--)
        {
            res2.pb('1');
            res2.pb('0');
        }

        // cout << res << " " << res2 << ln;
        for (int i = 0; i < res.length(); i++)
        {
            if (res[i] == '0')
            {
                sum += abs(oo.front() - i);
                oo.pop();
            }
        }

        for (int i = 0; i < res2.length(); i++)
        {
            if (res2[i] == '0')
            {
                sum2 += abs(ooo.front() - i);
                ooo.pop();
            }
        }

        cout << min(sum, sum2) << ln;
    }
    else
    {
        cout << -1 << ln;
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

/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
*/
