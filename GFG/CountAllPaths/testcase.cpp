#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("10out.txt", "r", stdin);
    freopen("10input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    map<pair<int, int>, int> m;
    m[{0, 0}]++;
    while (t--)
    {
        int a = 0, b = 0;
        while (m.count({a, b}))
        {
            a = (mt() % 100000) + 1;
            b = (mt() % 100000) + 1;
        }
        cout << a << " " << b << endl;
        cout << "~\n";
    }
    return 0;
}

//