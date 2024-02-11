#include <bits/stdc++.h>
using namespace std;

mt19937 mt;

int get()
{
    return (mt() % 9 + 1);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("1000out.txt", "r", stdin);
    freopen("1000input.txt", "w", stdout);
    // #endif
    int t;
    t = 10;
    cout << t << endl;
    while (t--)
    {
        int n = mt() % 50 + 1;
        int m = mt() % 50 + 1;
        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int res1 = mt() % 2;
                int res2 = mt() % 2;
                if (res1 + res2 == 2)
                {
                    cout << 0 << " ";
                }
                else
                {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }
        cout << "~\n";
    }
    return 0;
}

//