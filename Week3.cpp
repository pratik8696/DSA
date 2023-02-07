#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll skills, book;
ll req_skills;
ll abhi_hai;
vector<ll> books_price;
vector<ll> books_mask;
ll dp[101][1 << 15];
ll sum(ll idx, ll mask)
{
    if (idx == book)
    {
        if (mask == 0)
        {
            return 0;
        }
        return 1e9;
    }
    auto &x = dp[idx][mask];
    if (x != -1)
    {
        return x;
    }
    ll ans = 1e9;
    ll curr_mask = mask;
    ll curr_book_mask = books_mask[idx];
    for (ll i = 0; i < 16; i++)
    {
        if (curr_mask & (1 << i))
        {
            if (curr_book_mask & (1 << i))
            {
                curr_mask ^= (1 << i);
            }
        }
    }
    ans = min(ans, sum(idx + 1, curr_mask) + books_price[idx]);
    ans = min(ans, sum(idx + 1, mask));
    return x = ans;
}

void solve()
{
    cin >> skills >> book;
    cin >> req_skills;
    ll req = 0;
    for (ll i = 0; i < req_skills; i++)
    {
        ll x;
        cin >> x;
        x--;
        req |= (1 << x);
    }
    cin >> abhi_hai;
    ll not_req = 0;
    for (ll i = 0; i < abhi_hai; i++)
    {
        ll x;
        cin >> x;
        x--;
        not_req |= (1 << x);
    }
    ll mask = 0;
    for (ll i = 0; i < 17; i++)
    {
        if (req & (1 << i))
        {
            if ((not_req & (1 << i)) == 0)
            {
                mask |= (1 << i);
            }
        }
    }
    for (ll i = 0; i < book; i++)
    {
        ll x;
        cin >> x;
        books_price.push_back(x);
    }
    for (ll i = 0; i < book; i++)
    {
        ll x;
        cin >> x;
        ll y = 0;
        for (ll j = 0; j < x; j++)
        {
            ll temp;
            cin >> temp;
            temp--;
            y |= (1 << temp);
        }
        books_mask.push_back(y);
    }
    memset(dp, -1, sizeof(dp));
    cout << sum(0, mask) << endl;
}

int main()
{
    solve();
}
