#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int f(vector<int> &arr, int k)
{
    int n = arr.size();
    pbds back, front;
    for (auto t : arr)
    {
        back.insert(t);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        front.insert(arr[i]);
        back.erase(back.upper_bound(arr[i]));
        int f = 0, b = 0;
        if (front.size())
        {
            f = front.order_of_key(arr[i]);
        }
        if (back.size())
        {
            b = back.order_of_key(arr[i]);
        }
        if (f >= k && b >= k)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << f(arr, k) << endl;
}

string(string a, string b, string c)
{
    int i, n = a.length(), idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (c[i] != a[i] && c[i] != b[i])
        {
            idx = i;
        }
    }
    if (idx != -1)
    {
        return "-1";
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (i == idx)
        {
            string temp = "[";
            for(char j='A';j<='Z';j++)
            {
                if(j!=c[i])
                {
                    temp.pb(j);
                }
            }
            temp+="]";
        }
        else
        {
            ans+="[ABCDEFGHIJKLMNOPQRSTUVWXYZ]"
        }
    }
    return ans;
}