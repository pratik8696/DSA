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
typedef unsigned long long int ull;
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
#define forn(i, n) for (ll i = 0; i < n; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define alll(arr, n) (arr), (arr) + (n)
#define sz(x) ((ll)(x).size())

// function for prime factorization
vector<pair<ll, ll>> pf(ll n)
{
    vector<pair<ll, ll>> prime;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n = n / i;
            }
            prime.pb(mp(i, count));
        }
    }
    if (n > 1)
    {
        prime.pb(mp(n, 1));
    }
    return prime;
}

void solve()
{
    vector<pair<char, ll>> arr = {{'c', 1}, {'o', 1}, {'d', 1}, {'e', 1}, {'f', 1}, {'o', 1}, {'r', 1}, {'c', 1}, {'e', 1}, {'s', 1}};
    ll k, n, powe = 1;
    cin >> k;
    n = k;
    while (k != 0)
    {
        k = k / 2;
        powe *= 2;
    }
    // cout<<powe<<ln;
    vector<pair<ll, ll>> v = pf(powe);
    ll sum = 0, rem = 0;
    for (auto t : v)
    {
        // cout << t.first << " " << t.second << ln;
        ll full = 0, rem = 0;
        full = t.second / 10;
        rem = t.second % 10;
        if (full != 0)
        {
            for (int i = 0; i < 10; i++)
            {
                arr[i].second *= pow(t.first, full);
            }
        }
        for (int i = 0; i < rem; i++)
        {
            arr[i].second *= pow(t.first, 1);
        }
    }
    // for (auto t : arr)
    // {
    //     cout << t.first << " ";
    // }
    // cout << ln;
    // for (auto t : arr)
    // {
    //     cout << t.second << " ";
    // }
    // cout << ln;
    string res = "";
    for (auto t : arr)
    {
        for (int i = 1; i <= t.second; i++)
        {
            res.pb(t.first);
        }
    }
    cout << res << ln;
}
// 2048 4096 8192
/*
7-->ccooddeforces
8-->ccooddeforces
421654016-->ccccccccooooooooddddddddeeeeeeefffffffooooooorrrrrrrccccccceeeeeeesssssss
421654016-->ccccccccooooooooddddddddeeeeeeeeffffffffoooooooorrrrrrrrcccccccceeeeeeeessss
1537-->cccoooddeeffoorrcceess
1537-->ccccooddeeffoorrcceess
        4 2 2 2 2 2 2 2 2 2
666666-->ccccooooddddeeeeffffoooorrrrcccceeeesss
666666-->ccccooooddddeeeeffffoooorrrrcccceeeessss
10000000000000000-->ccccccccccccccccccccccccccccccccccccccccooooooooooooooooooooooooooooooooooooooooddddddddddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeffffffffffffffffffffffffffffffffffffffffoooooooooooooooooooooooooooooooooooooooorrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrcccccccccccccccccccccccccccccccccccccccceeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeesssssssssssssssssssssssssssssssssssssss
10000000000000000-->ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeffffffffffffffffffffffffffffffffoooooooooooooooooooooooooooooooorrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrcccccccccccccccccccccccccccccccceeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeessssssssssssssssssssssssssssssss
// */
//  2 2 2 2 2 2 2 2 2 2
//  4 4    4  4   4    4   4  4   4   3
//  2 2    2  2   2    2   2   2   2
//  1 2    3  4   5    6   7   8   9

int main()
{
    fast_cin();
    // ll t;
    // cin >> t;
    // for (int it = 1; it <= t; it++)
    // {
    solve();
    // }
    return 0;
}