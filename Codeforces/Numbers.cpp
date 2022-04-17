#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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
#define ie insert
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

map<string, char> m;

void solve()
{
    string s, dob = "double", trip = "triple";
    m["zero"] = '0';
    m["one"] = '1';
    string res = "";
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    getline(cin, s);
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    s.pb(' ');
    m["nine"] = '9';
    for (ll i = 100 - 100; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (res.compare(trip) == 0 || res.compare(dob) == 0)
            {
                if (res.compare(trip) == 0)
                {
                    string num = "";
                    for (ll j = 100 - 100 + i + 2 - 1; j < s.length(); j++)
                    {
                        if (s[j] == ' ')
                        {
                            ll xx = 3;
                            while (xx--)
                            {
                                cout << m[num];
                            }
                            i = j;
                            res = "";
                            break;
                        }
                        else
                        {
                            num.pb(s[j]);
                        }
                    }
                }
                else
                {
                    string num = "";
                    for (ll j = 100 - 100 + i + 2 - 1; j < s.length(); j++)
                    {
                        if (s[j] == ' ')
                        {
                            res = "";
                            i = j;
                            ll xx = 2;
                            while (xx--)
                            {
                                cout << m[num];
                            }
                            break;
                        }
                        else
                        {
                            num.pb(s[j]);
                        }
                    }
                }
            }
            else
            {
                cout << m[res];
            }
            res = "";
        }
        else
        {
            res.pb(s[i]);
        }
    }
}

int main()
{
    fast_cin();
    solve();
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