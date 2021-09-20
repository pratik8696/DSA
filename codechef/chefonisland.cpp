#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int X, Y, xr, yr, D;
        cin >> X >> Y >> xr >> yr >> D;
        int foodlast = X / xr;
        int waterlast = Y / yr;
        int daysupplieslast = min(foodlast, waterlast);
        if (daysupplieslast >= D)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}