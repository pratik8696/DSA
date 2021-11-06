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
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int hash[5];
    int hash1[5];
    // int hash2[5];
    // int hash3[5];
    fill(al(hash, 5), 0);
    fill(al(hash1, 5), 0);
    forn(i, n)
    {
        cin >> arr[i];
        hash[arr[i]]++;
        hash1[arr[i]]++;
        // hash2[arr[i]]++;
        // hash3[arr[i]]++;
    }
    int count = 0;
    // for (int i = 1; i < 5; i++)
    // {
    //     cout << hash[i] << " ";
    // }
    // cout << ln;
    sort(al(arr, n));

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1 && hash[1] >= 4)
        {
            count++;
            hash[arr[i]] = hash[arr[i]] - 4;
        }
        else if (hash[1] >= 2 && hash[2] > 0)
        {
            count++;
            hash[2]--;
            hash[1]--;
            hash[1]--;
        }
        else if(hash[4]>0)
        {
            count=hash[4];
            hash[4]=0;
        }
        else if (hash[1] <= 3 && hash[2] == 0 && hash[3] == 0)
        {
            count++;
            hash[1] = 0;
        }
        else if (hash[1] == 1 && hash[2] == 1)
        {
            count++;
            hash[2]--;
            hash[1]--;
        }
        else if (arr[i] == 2 && hash[2] >= 2)
        {
            count++;
            hash[2] = hash[2] - 2;
        }
        else if (hash[4 - arr[i]] > 0 && hash[arr[i]] > 0 && arr[i] != 2)
        {
            hash[4 - arr[i]]--;
            hash[arr[i]]--;
            count++;
        }
        else if (hash[arr[i]] > 0)
        {
            hash[arr[i]]--;
            count++;
        }
        int k = 0;
        for (int i = 1; i < 5; i++)
        {
            // cout << hash[i] << " ";
            if (hash[i] != 0)
            {
                k++;
            }
        }
        // cout << ln;
        if (k == 0)
        {
            break;
        }
    }

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 2 && hash1[2] >= 2)
        {
            count1++;
            hash1[2] = hash1[2] - 2;
        }
        else if (hash1[4 - arr[i]] > 0 && hash1[arr[i]] > 0 && arr[i] != 2)
        {
            hash1[4 - arr[i]]--;
            hash1[arr[i]]--;
            count1++;
        }
        else if (hash1[arr[i]] > 0)
        {
            hash1[arr[i]]--;
            count1++;
        }
        int k = 0;
        for (int i = 1; i < 5; i++)
        {
            if (hash1[i] != 0)
            {
                k++;
            }
        }

        if (k == 0)
        {
            break;
        }
    }
    // cout << count << " " << count1 << ln;
    cout << min(count1, count) << ln;
}
int main()
{
    fast_cin();
    //  ll t;
    //  cin >> t;
    //  for(int it=1;it<=t;it++) {
    solve();
    //  }
    return 0;
}
