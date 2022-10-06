#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int N, idx;
tree<int, null_type, less<int>, rb_tree_tag,
     tree_order_statistics_node_update>
    T;
typedef long long ll;
const ll M = 1e9 + 7;
const ll M_ = 1e7 + 10;

vector<ll> v;
ll n, k;

bool check(double mid)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        double x = floor(v[i] / mid);
        ll y = floor(x);
        sum += y;
    }
    if (sum < k)
    {
        return false;
    }
    return true;
}

int main()
{
    cin >> n >> k;
    v.resize(n);
    ll maxi = INT_MIN;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    double l = 1, r = 1e18, ans = 1e8;
    for (ll i = 1; i <= 100; i++)
    {
        double mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << fixed << setprecision(12) << ans << endl;
}