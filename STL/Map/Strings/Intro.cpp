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
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
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

void solve()
{
}
int main()
{
    fast_cin();
    string s0;
    if (s0.empty())
    {
        cout << "The string is currently empty" << endl;
    }
    else
    {
        cout << "The string is filled" << endl;
    }
    s0.append("I love c++");
    if (s0.empty())
    {
        cout << "The string is currently empty" << endl;
    }
    else
    {
        cout << "The string is filled" << endl;
    }
    cout << "The length of the string is = " << s0.length() << endl;
    string s1;
    cin >> s1;
    cout << "Comparing 2 strings " << s0.compare(s1) << endl;
    cout << "Comparing 2 strings " << s0.compare(s0) << endl;
    // now using overloaded operators;
    if (s1 > s0)
    {
        cout << "Second string is larger than first string" << endl;
    }
    else
    {
        cout << "second string is smaller" << endl;
    }
    // now searching a particular word in a sentence;
    string sentence;
    cin.get();
    getline(cin, sentence);
    string wordtofind;
    cin >> wordtofind;
    cout << sentence << endl;
    int index = sentence.find(wordtofind);
    cout << "The index of the word " << wordtofind << " is " << index << endl;
    // now removing that word from the sentence
    sentence.erase(index,wordtofind.length()+1);
    cout<<sentence<<endl;
    return 0;
}