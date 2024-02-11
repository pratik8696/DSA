#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// function for fast expo
ll fastexpo(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (a == 0)
    {
        return 0;
    }
    ll y = fastexpo(a, b / 2);
    if (b % 2 == 0)
    {
        return y * y;
    }
    else
    {
        return a * y * y;
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("1000out.txt", "r", stdin);
    freopen("1000input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 1;
    cout << t << endl;
    while (t--)
    {
        int n = 100000;
        int m = 100000;
        cout << n << " " << m << endl;
        vector<long long> arrival(n);
        vector<long long> dep(n);
        vector<long long> queries(m);
        for (int i = 0; i < n; i++)
        {
            arrival[i] = mt() % fastexpo(10, mt() % 15 + 1) + 1;
        }
        for (int i = 0; i < n; i++)
        {
            while (dep[i] < arrival[i])
            {
                dep[i] = mt() % fastexpo(10, mt() % 15 + 1) + 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            // now take queries
            queries[i] = mt() % fastexpo(10, mt() % 15 + 1) + 1;
        }
        for (auto t : arrival)
        {
            cout << t << " ";
        }
        cout << endl;
        for (auto t : dep)
        {
            cout << t << " ";
        }
        cout << endl;
        for (auto t : queries)
        {
            cout << t << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}