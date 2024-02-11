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
        int x = 0;
        for (int i = 0; i < 3; i++)
        {
            x = x * 10 + get();
        }
        cout << x << endl;
        cout << "~\n";
    }
    return 0;
}

//