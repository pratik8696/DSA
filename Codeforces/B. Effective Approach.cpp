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
#define sz(x) ((ll)(x).size())

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int binarysearch(vector<pair<int, int>> arr, int k)
{
    int s = 0, e = arr.size() - 1, mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid].first == k)
        {
            return mid;
        }
        else if (arr[mid].first > k)
        {
            e = mid - 1;
        }
        else if (arr[mid].first < k)
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n,k,q,idx;
    cin >> n;
    vector<pair<int, int>> arr;
    forn(i, n)
    {
        int k;
        cin >> k;
        arr.pb(make_pair(k, i));
    }
    sort(all(arr), compare);
    cin >> q;
    int lcount = 0, rcount = 0;
    while (q--)
    {
        
        cin >> k;
        idx = binarysearch(arr, k);
        lcount += arr[idx].second + 1;
        rcount += n - arr[idx].second;
    }
    cout << lcount << " " << rcount << endl;
    return 0;
}