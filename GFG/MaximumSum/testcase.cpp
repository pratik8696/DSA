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
        int n = mt() % 1000;
        n++;
        int r = mt() % 1000;
        r++;
        int x = mt() % 1000;
        x++;
        cout << n << " " << r << " " << x << endl;
        cout << "~" << endl;
    }
    return 0;
}

//