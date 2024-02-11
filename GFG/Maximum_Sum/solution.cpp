// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution
{
public:
    long long maximumSum(int n, int brr[], int arr[], int x)
    {
        vector<ll> a, awt;
        vector<ll> b, bwt;
        for (int i = 0; i < n / 2; i++)
        {
            a.push_back(arr[i]);
            awt.push_back(brr[i]);
        }
        for (int i = n / 2; i < n; i++)
        {
            b.push_back(arr[i]);
            bwt.push_back(brr[i]);
        }
        // generate all combinations
        map<ll, ll> m;

        for (int mask = 0; mask < int(pow(2, a.size())); mask++)
        {
            ll sumofa = 0;
            ll wtofa = 0;
            for (int i = 0; i < a.size(); i++)
            {
                if (mask & (1 << i))
                {
                    sumofa += a[i];
                    wtofa += awt[i];
                }
            }
            m[sumofa] = max(m[sumofa], wtofa);
        }

        ll ans = 0;
        //  generate all combinations of b
        for (int mask = 0; mask < int(pow(2, b.size())); mask++)
        {
            ll sumofb = 0;
            ll wtofb = 0;
            for (int i = 0; i < b.size(); i++)
            {
                if (mask & (1 << i))
                {
                    sumofb += b[i];
                    wtofb += bwt[i];
                }
            }
            if (m.count(x - sumofb))
            {
                ans = max(ans, wtofb + m[x - sumofb]);
            }
        }

        return ans;
    }
};

int main()
{
    freopen("10in.txt", "r", stdin);
    freopen("10out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        cin >> x;
        char hh;
        cin>>hh;
        Solution obj;
        cout << obj.maximumSum(n, a, b, x) << endl;
        cout<<"~"<<endl;
    }
    return 0;
}