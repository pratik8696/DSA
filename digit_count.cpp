#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll val;
ll dp[18][2][18];
ll sum(ll idx, bool last, ll summ)
{
    if (idx == s.length())
    {
        return summ;
    }
    if (dp[idx][last][summ] != -1)
    {
        return dp[idx][last][summ];
    }
    ll till = last ? s[idx] - '0' : 9;
    ll ans = 0;
    for (int i = 0; i <= till; i++)
    {
        if (i == val)
        {
            ans += sum(idx + 1, last && (i == till), summ + 1);
        }
        else
        {
            ans += sum(idx + 1, last && (i == till), summ);
        }
    }
    return dp[idx][last][summ] = ans;
}

unordered_map<ll, ll> f(string x)
{
    unordered_map<ll, ll> res;
    s = x;
    for (int i = 1; i <= 9; i++)
    {
        val = i;
        memset(dp, -1, sizeof(dp));
        res[i] = sum(0, true, 0);
    }
    return res;
}

int main()
{
    while (1)
    {
        string n, m;
        cin >> n >> m;
        if (n == "0" && m == "0")
        {
            exit(0);
        }
        ll i = n.length() - 1;
        while (i >= 0 && n[i] == '0')
        {
            n[i] = '9';
        }
        n[i]--;
        unordered_map<ll, ll> a = f(m);
        unordered_map<ll, ll> b = f(n);
        for (int i = 1; i <= 9; i++)
        {
            cout << a[i] - b[i] << " ";
        }
    }
    return 0;
}
