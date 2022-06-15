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
typedef long long ll;
// use less_equal to make it multiset
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef unsigned long long ull;
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
typedef vector<pair<p64, ll>> vpp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef multiset<ll> ms64;
typedef multiset<p64> msp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef unordered_map<ll, v64> uv64;
typedef unordered_map<ll, ll> u64;
typedef unordered_map<p64, ll> up64;
typedef unordered_map<ll, vp64> uvp64;
typedef priority_queue<ll> pq64;
typedef priority_queue<ll, v64, greater<ll>> pqs64;
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

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        // connect the recipies to the ingredients
        unordered_map<ll, vector<string>> adj;
        set<string> check;
        for (auto t : recipes)
        {
            check.ie(t);
        }
        map<string, ll> indegree;
        forn(i, ingredients.size())
        {
            auto &x = ingredients[i];
            for (auto t : x)
            {
                adj[recipes[i]].pb(t);
                indegree[t]++;
            }
        }
        for (auto t : supplies)
        {
            indegree[t]--;
        }
        queue<string> q;
        for (auto t : indegree)
        {
            if (t.se == 0)
            {
                q.push(t.fi);
            }
        }
        vector<string> ans;
        while (!q.empty())
        {
            string curr = q.front();
            if (check.count(curr))
            {
                ans.pb(curr);
            }
            q.pop();
            for (auto child : adj[curr])
            {
                indegree[child]--;
                if (indegree[child] == 0)
                {
                    q.push(child);
                }
            }
        }
        return ans;
    }
};