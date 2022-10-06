#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int N, idx;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> T;
typedef long long ll;
const ll M = 1e9 + 7;
const ll M_ = 1e7 + 10;

vector<ll> w;
vector<ll> c;
vector<ll> v;

int main()
{
    ll n, k;
    cin >> n >> k;
    v.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll i = 0, j = 0;
    while (j < n)
    {
        T.insert(v[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (k % 2 == 0)
            {
                ll a = *(T.find_by_order(k / 2));
                ll b = *(T.find_by_order(((k + 1) / 2)));
                cout << min(a, b) << " ";
            }
            else
            {
                ll a = *(T.find_by_order(k / 2));
                cout << a << " ";
            }
            T.erase(T.upper_bound(v[i]));
            i++;
            j++;
        }
        
    }
}