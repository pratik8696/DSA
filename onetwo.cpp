#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    ll gcd = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        gcd = __gcd(arr[i], gcd);
    }
    // pf
    vector<int> f;
    for (ll i = 1; i * i <= gcd; i++)
    {
        if(gcd%i==0)
        {
            if(gcd/i==i)
            {
                f.push_back(gcd / i);
            }
            else
            {
                f.push_back(gcd/i);
                f.push_back(i);
            }
        }
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll a,b,cc=0;
        cin>>a>>b;
        for(auto t:f)
        {
            if(t>=a&&t<=b)
            {
                cc+=t;
            }
        }
        cout<<cc<<endl;
    }
}

int main()
{
    solve();
}
