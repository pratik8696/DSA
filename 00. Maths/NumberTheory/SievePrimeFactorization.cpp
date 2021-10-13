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

vector<int> sieve()
{
    int MAX=1000;
    bool arr[MAX];
    vector<int> prime;
    prime.clear();
    fill(arr, arr + MAX, true);
    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i < MAX; i++)
    {
        if (arr[i] == true)
        {
            prime.pb(i);
            for (int j = i * i; j < MAX; j += i)
            {
                arr[j] = false;
            }
        }
    }
    return prime;
}

void sieveprimefactors(int n, vector<int> prime)
{
    for (int j = 0, i = prime[j]; prime[j] < sqrt(n); j++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n = n / i;
                count++;
            }
            cout << i << " " << count<<endl;
        }
    }

    if (n > 1)
    {
        cout << n << " " << 1 << endl;
    }
}
void solve(vector<int> prime)
{
    int n;
    cin >> n;
    sieveprimefactors(n, prime);
}
int main()
{
    fast_cin();
    vector<int> p = sieve();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve(p);
    }
    return 0;
}