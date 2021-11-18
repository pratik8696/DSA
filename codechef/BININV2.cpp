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
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr,n) arr,arr+n
#define sz(x) ((ll)(x).size())

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll j;
    pair<pair<ll, ll>, string> s[n];
    for (j = 0; j < n; j++)
    {
        cin >> s[j].second;
        ll c_1 = 0, val = 0, c_0 = 0;
        for (ll k = m - 1; k >= 0; k--)
        {
            if (s[j].second[k] == '1')
            {
                val += c_0;
                c_1++;
            }
            else
            {
                c_0++;
            }
        }
        s[j].first = {c_1, val};
    }
    sort(s, s + n);
    string temp = "";
    for (j = 0; j < n; j++)
    {
        temp += s[j].second;
    }

    ll ans = 0, c_0 = 0, c_1 = 0;
    for (j = temp.length() - 1; j >= 0; j--)
    {
        if (temp[j] == '1')
        {
            ans += c_0;
            c_1++;
        }
        else
        {
            c_0++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}