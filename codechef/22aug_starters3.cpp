#include <iostream>
using namespace std;

int main()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    int tt = 240;
    int counta = 0, countb = 0, countc = 0;
    while (tt > 0)
    {
        if (counta < 20)
        {
            tt = tt - a;
            counta++;
        }
    }
    // while (tt != 0)
    // {
    //     if (countb != 20)
    //     {
    //         tt = tt - b;
    //         countb++;
    //     }
    // }
    // while (tt != 0)
    // {
    //     if (countc != 20)
    //     {
    //         tt = tt - c;
    //         countc++;
    //     }
    // }
    // int maxpt = counta * x + countb * y + countc * z;
    // cout << maxpt << endl;
    return 0;
}