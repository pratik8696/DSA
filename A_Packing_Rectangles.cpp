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

ll w, h, n;
bool check(ll mid)
{
    return ((mid / w) * (mid / h)) >= n;
}

int main()
{
    cin >> w >> h >> n;
    ll l = 0, r = 1e9, ans = -1;
    while (l <= r)
    {
        ll mid = r + (l - r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}