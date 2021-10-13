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
// function to calculate all the prime factors and
// count of every prime factor
ll oddsum = 0;

void factorize(long long n, ll a, ll b)
{
    vector<pair<int, int>> v;
    int org = n;
    int count = 0, evensum = 0;
    while (!(n % 2))
    {
        n /= 2;
        count++;
        evensum++;
    }
    if (count)
    {
        // cout << 2 << "\t" << count << endl;
    }

    count = 0;
    n = org;
    for (long long i = 3; i <= sqrt(n)+1; i += 2)
    {
        n = org;
        // count = 0;
        while (n % i == 0)
        {
            count++;
            oddsum++;
            n = n / i;
        }
        // if (count)
        //     cout << i << "\t" << count << endl;
        // oddsum += count;
    }
    if (n > 2)
        // cout << n << "\t" << 1 << endl;

        cout << evensum << " " << oddsum << endl;
    oddsum = 0;
    ll res = 0;

    // if (a > 0 && b > 0)
    // {
    //     res=evensum*a+oddsum*b;
    // }
    // else if(a>0 && b< 0)
    // {
    //     res = evensum * a +  b;
    // }
    // else if (a < 0 && b > 0)
    // {
    //     res =  a + oddsum*b;
    // }

    // else if(a<=0 && b<=0)
    // {
    //     if(n%2==0)
    //     {
    //         res=a;
    //     }
    //     else{
    //         res=b;
    //     }
    // }

    // cout<<res<<endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long n, a, b;
        cin >> n >> a >> b;
        factorize(n, a, b);
    }
    return 0;
}
