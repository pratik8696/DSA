#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("1000output.txt", "r", stdin);
    freopen("1000input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 1;
    cout << t << endl;
    while (t--)
    {
        map<vector<int>, int> hsh;
        hsh[{0, 0, 0}]++;
        int n = 100000/2;
        int m = 100000/2;
        cout << n << " " << m << endl;
        while(m--)
        {
            int u = 0, v = 0, wt = 0;
            while (hsh.count({u, v, wt}))
            {
                u = (mt() % n) + 1;
                v = (mt() % n) + 1;
                wt = (mt() % 100000) + 1;
            }
            hsh[{u, v, wt}]++;
            cout << u << " " << v << " " << wt << endl;
        }
        // cout << sum << endl;
        cout << "~\n";
    }
    return 0;
}