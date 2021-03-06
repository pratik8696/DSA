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
    // 9--> 1001
    // 21--> 10101
    // 1+4+16  (3)
    // 1+4+8+8
    // 1+2+2+16 (4)
    // 1+1+1+2+16
    // 1+1+1+1+1+16
    // 1+1+1+1+1+8+8
    ll n, k;
    cin >> n >> k;
    ll count = __builtin_popcount(n);
    if (k >= count && k <= n)
    {
        priority_queue<ll> pq;
        string s = bitset<65>(n).to_string();
        reverse(all(s));
        forn(i, s.length())
        {
            if (s[i] == '1')
            {
                pq.push(pow(2ll, i));
            }
        }
        while (pq.size() != k)
        {
            ll largest = pq.top();
            pq.pop();
            largest = largest / 2;
            pq.push(largest);
            pq.push(largest);
        }
        cout << "YES" << ln;
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    }
    else
    {
        cout << "NO" << ln;
    }
}
int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
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
