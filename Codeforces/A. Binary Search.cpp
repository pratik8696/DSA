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

bool binary(int s, int e, ll arr[], int q)
{
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == q)
        {
            return true;
        }
        else if (arr[mid] > q)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return false;
}
int main()
{
    int n, k;
    cin >> n >> k;
    ll arr[n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < k; i++)
    {
        int q;
        cin >> q;
        if(binary(0, n - 1, arr, q))
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}