#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("7out.txt", "r", stdin);
    freopen("7input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    while (t--)
    {
        map<pair<int, int>, int> m;
        m[{0, 0}]++;
        int n = 1000;
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            int x = 0, y = 0;
            while (m.count({x, y}))
            {
                x = mt() % int(1e5) + 1;
                y = mt() % int(1e5) + 1;
            }
            cout << x << " " << y << endl;
            m[{x, y}]++;
        }
        cout << "~\n";
    }
    return 0;
}
