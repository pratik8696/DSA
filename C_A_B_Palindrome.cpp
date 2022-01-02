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
    int zero, one, on, oz;
    cin >> zero >> one;
    oz = zero, on = one;
    string s;
    cin >> s;

    forn(i, s.length())
    {
        if (s[i] == '0')
        {
            zero--;
        }
        else if (s[i] == '1')
        {
            one--;
        }
    }
    if (one < 0 || zero < 0)
    {
        cout << -1 << ln;
        return;
    }
    if (s.length() == 1)
    {
        if (s[0] != '?')
        {
            cout << s << ln;
            return;
        }
        else
        {
            if (on > 0)
            {
                cout << 1 << ln;
                return;
            }
            else if (oz > 0)
            {
                cout << 0 << ln;
                return;
            }
            else
            {
                cout << -1 << ln;
                return;
            }
        }
    }
    string p = "", q = "";
    for (int i = 0; i < s.length() / 2; i++)
    {
        p.pb(s[i]);
    }
    ll start = s.length() / 2;
    if (s.length() % 2 != 0)
    {
        start++;
    }
    for (int i = start; i < s.length(); i++)
    {
        q.pb(s[i]);
    }
    if (one == 0 && zero == 0)
    {
        string rev = s;
        reverse(all(rev));
        if (rev.compare(s) == 0)
        {
            cout << s << ln;
        }
        else
        {
            cout << -1 << ln;
            return;
        }
    }
    reverse(all(q));
    // cout << p << " " << q << ln;
    for (int i = 0; i < s.length() / 2; i++)
    {
        // cout << zero << " " << one << ln;
        // cout << p[i] << " " << q[i] << ln;
        if (p[i] == '?' && q[i] != '?')
        {
            if (q[i] == '0' && zero > 0)
            {
                p[i] = '0';
                zero--;
            }
            else if (q[i] == '1' && one > 0)
            {
                p[i] = '1';
                one--;
            }
            else
            {
                cout << -1 << ln;
                // cout << ln << ln;
                return;
            }
        }
        else if (p[i] != '?' && q[i] == '?')
        {
            if (p[i] == '0' && zero > 0)
            {
                q[i] = '0';
                zero--;
            }
            else if (p[i] == '1' && one > 0)
            {
                q[i] = '1';
                one--;
            }
            else
            {
                cout << -1 << ln;
                // cout << ln << ln;
                return;
            }
        }
        else if (p[i] == '?' && q[i] == '?')
        {
            if (one >= zero && one > 1)
            {
                p[i] = '1';
                q[i] = '1';
                one--;
                one--;
            }
            else if (zero > one && zero > 1)
            {

                p[i] = '0';
                q[i] = '0';
                zero--;
                zero--;
            }
            else
            {
                cout << -1 << ln;
                return;
                // cout << ln << ln;
            }
        }
        // cout << p[i] << " " << q[i] << ln;
    }
    reverse(all(q));
    cout << p;
    if (s.length() % 2 != 0)
    {
        if (s[s.length() / 2] != '?')
        {
            cout << s[s.length() / 2];
        }
        else if (one > 0)
        {
            cout << 1;
        }
        else if (zero > 0)
        {
            cout << 0;
        }
        else
        {
            cout << -1 << ln;
            return;
        }
    }
    cout << q << ln;
    // cout << ln << ln;
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
