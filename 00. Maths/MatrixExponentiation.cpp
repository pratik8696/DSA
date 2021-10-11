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

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
    // store the result
    vector<vector<ll>> C(A.size() + 1, vector<ll>(A.size() + 1));

    // logic to multiply
    for (int i = 0; i <= A.size(); i++)
    {
        for (int j = 0; j <= A.size(); j++)
        {
            for (int x = 0; x <= A.size(); x++)
            {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> T, int p)
{
    if (p == 1)
    {
        return T;
    }

    if (p & 1)
    {
        return multiply(T, power(T, p - 1));
    }
    else
    {
        vector<vector<ll>> x = power(T, p / 2);
        return multiply(x, x);
    }
}

int compute(int t, int arrb[], int arrc[], int k)
{
    if (t == 0)
    {
        return 0;
    }

    // forming F1 matrix;
    vector<int> f1(k + 1);
    for (int i = 1; i <= k; i++)
    {
        f1[i] = arrb[i];
    }

    // forming the transformation matrix
    vector<vector<ll>> T(k + 1, vector<ll>(k + 1));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < k)
            {
                if (j == i + 1)
                {
                    T[i][j] = 1;
                }
                else
                {
                    T[i][j] = 0;
                }
            }
            else
            {
                T[i][j] = arrc[k - j];
            }
        }
    }

    T = power(T, t - 1);

    // multiply F1 and T^(n-1)
    ll res = 0;
    for (int i = 1; i <= k; i++)
    {
        res = (res + (T[1][i] * f1[i]) % MOD) % MOD;
    }
    return res;
}

// solving linear recurrences
void solve()
{
    // so its like {Fn = T^(n-1) * F1}
    int k;
    cin >> k;

    // taking in b
    int arrb[k];
    forn(i, k)
    {
        cin >> arrb[i];
    }

    // taking in values of coefficient
    int arrc[k];
    forn(i, k)
    {
        cin >> arrc[i];
    }

    int t;
    cin >> t;

    cout << compute(t, arrb, arrc, k) << endl;
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