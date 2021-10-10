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

struct Stack
{
    int size;
    int top;
    int *s;
};

int push(struct Stack *s, int x)
{
    s->top++;
    s->s[s->top] = x;
}

int pop(struct Stack *s)
{
    int x = s->s[s->top];
    s->top--;
    return x;
}

int peek(struct Stack s,int x)
{
    return s.s[s.top-x+1];
}

bool isempty(struct Stack s)
{
    if (s.top == -1)
    {
        return true;
    }

    return false;
}

bool isfull(struct Stack s)
{
    if (s.top == s.size-1)
    {
        return true;
    }

    return false;
}

bool stacktop(struct Stack s)
{
    return s.s[s.top];
}

int main()
{
    fast_cin();
    struct Stack st;
    cout << "Enter the size of the stack " << endl;
    cin >> st.size;
    st.top = -1;
    st.s = new int[st.size];
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    cout << peek(st, 4) << " " << peek(st, 3) << " " << peek(st, 2) << " " << peek(st, 1) << endl;

    return 0;
}