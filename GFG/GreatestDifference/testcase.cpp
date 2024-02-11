#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("1000output.txt", "r", stdin);
    freopen("1000input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 1000;
    cout << t << endl;
    while (t--)
    {
        int n = 1000;
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << (mt() % 10000000) + 1 << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

//