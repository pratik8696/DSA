#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll check_vowel(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return 1;
    else
        return 0;
}

ll check_cons(char x)
{
    if (x != 'a' || x != 'e' || x != 'i' || x != 'o' || x != 'u')
        return 1;
    else
        return 0;
}

void solve()
{
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            ans += 0;
        }
        else if (a[i] != '?' && b[i] != '?')
        {
            if (check_vowel(a[i]) && check_vowel(b[i]))
            {
                ans += 2;
            }
            else
            {
                if (check_cons(a[i]) && check_cons(b[i]))
                    ans += 2;
                else
                    ans += 1;
            }
        }
    }
    ll ans2 = INT_MAX;

    for (char x = 'a'; x <= 'z'; x++)
    {
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            if ((a[i] == '?' && b[i] != '?'))
            {
                if (x == b[i])
                    cnt += 0;
                else if ((x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') && ((b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u')))
                {
                    cnt += 2;
                }
                else if ((x != 'a' || x != 'e' || x != 'i' || x != 'o' || x != 'u') && ((b[i] != 'a' || b[i] != 'e' || b[i] != 'i' || b[i] != 'o' || b[i] != 'u')))
                    cnt += 2;
                else
                    cnt += 1;
            }
            if ((a[i] != '?' && b[i] == '?'))
            {
                if (x == a[i])
                    cnt += 0;
                else if ((x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') && ((a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')))
                {
                    cnt += 2;
                }
                else if ((x != 'a' || x != 'e' || x != 'i' || x != 'o' || x != 'u') && ((a[i] != 'a' || a[i] != 'e' || a[i] != 'i' || a[i] != 'o' || a[i] != 'u')))
                    cnt += 2;
                else
                    cnt += 1;
            }
        }
        ans2 = min(cnt, ans2);
    }

    cout << ans2 << endl;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}