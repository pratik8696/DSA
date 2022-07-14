#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;

vector<int> fun(ll n)
{
    vector<int> factors;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (n / i != i)
            {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

void solve()
{
    ll n;
    cin >> n;
    unordered_map<ll, vector<int>> adj;
    unordered_map<ll, ll> indegree;
    unordered_map<ll, ll> routes;
    vector<int> v = fun(n);
    queue<ll> q;
    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = 0; j < v.size(); j++)
        {
            if (i != j)
            {
                ll val1 = v[i];
                ll val2 = v[j];
                if (val1 % val2 == 0)
                {
                    adj[val1].push_back(val2);
                    indegree[val2]++;
                }
            }
        }
    }

    for (auto t : v)
    {
        if (indegree[t] == 0)
        {
            q.push(t);
            routes[t] = 1;
        }
    }

    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        for (auto child : adj[curr])
        {
            routes[child] += routes[curr];
            routes[child] %= MOD;
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }

    cout << routes[1] << endl;
}

int main()
{
    solve();
    return 0;
}
