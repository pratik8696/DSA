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

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void Create(int arr[], int k)
{
    struct Node *last, *t;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < k; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout << "LINKED LIST CREATED SUCCESSFULLY!!!" << endl;
}

int Nodes(struct Node *p)
{
    int node = 0;
    while (p != NULL)
    {
        node++;
        p = p->next;
    }
    return node;
}

void Insert(int x, int pos, struct Node *p)
{
    struct Node *temp = new Node;
    temp->data = x;
    if (pos == 1)
    {
        temp->next = p;
        p = temp;
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void Display(struct Node *p)
{
    cout << "The elements in list are " << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << ln;
}

void insertsort(struct Node *p,int x)
{
    struct Node *q=NULL;
    struct Node *t=new Node;
    t->data=x;
    t->next=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        if(p->data>q->data)
        {
            t->next=q->next;
            q->next=t;
        }
    }
    if(p==NULL)
    {
        t->next=p;
        q->next=t;
    }
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    Create(arr, n);
    Display(first);
    cout << "No of Nodes = " << Nodes(first) << ln;
    Insert(10, 1, first);
    cout << "The list after insertion" << ln;
    Display(first);
    insertsort(first,10);
    Display(first);
}

int main()
{
    fast_cin();
    solve();
    return 0;
}