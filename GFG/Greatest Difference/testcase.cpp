#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("1output.txt", "r", stdin);
    freopen("1input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    while (t--)
    {
        cout << mt() % 1000000 << endl;
        cout << "~" << endl;
    }
    return 0;
}

//