#include <bits/stdc++.h>
using namespace std;

int robotTour()
{
    int n, x = 0, y = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
        {
            x++;
        }
        if (s[i] == 'D')
        {
            x--;
        }
        if (s[i] == 'R')
        {
            y++;
        }
        if (s[i] == 'L')
        {
            y--;
        }
    }
    return abs(x) + abs(y);
}

int main()
{
    cout << robotTour();
    return 0;
}
