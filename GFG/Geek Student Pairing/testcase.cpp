#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("1000out.txt", "r", stdin);
    freopen("1000input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 1;
    cout << t << endl;
    while (t--)
    {
        int n = 10000;
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << mt() % 100000000 + 1 << " " << mt() % 100000000 + 1 << endl;
        }
        for (int i = 0; i < n; i++)
        {
            cout << mt() % 100000000 + 1 << " " << mt() % 100000000 + 1 << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

//