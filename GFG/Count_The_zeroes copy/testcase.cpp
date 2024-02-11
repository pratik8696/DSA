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
    t = 100;
    cout << t << endl;
    while (t--)
    {
        int n = mt() % 10000 + 1;
        cout << n << endl;
        int x = mt() % n;
        for (int i = 0; i < x; i++)
        {
            cout << "1 ";
        }
        for (int i = 0; i < n - x; i++)
        {
            cout << "0 ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}
