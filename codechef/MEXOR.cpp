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

    // ll x=1000000001;
    // // cin >> x;
    // ll o = 0, i;
    // ll prevor=0;
    // ll curror=0;
    // vector<int> v;
    // v.pb(0);
    // for (i = 0; i <= x ; i++)
    // {
    //     curror=curror|i;
    //     if(curror!=prevor)
    //     {
    //         v.pb(curror);
    //         prevor=curror;
    //     }
    // }
    // for(auto p:v)
    // {
    //     cout<<p<<" ";
    // }
    // ll n;
    // cin>>n;
    
    
    // cout<<ln;
void solve()
{
    vector<ll> v = { 0 ,1 ,3 ,7 ,15 ,31, 63 ,127 ,255 ,511 ,1023, 2047 ,4095 ,8191, 16383 ,32767 ,65535 ,131071 ,262143 ,524287 ,1048575, 2097151 ,4194303 ,8388607 ,16777215 ,33554431 ,67108863 ,134217727 ,268435455 ,536870911, 1073741823 };
    ll x;
    cin>>x;
    ll idx=upper_bound(v.begin(),v.end(),x)-v.begin()-1;
    cout<<v[idx]+1<<endl;

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