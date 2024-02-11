#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("10output.txt", "r", stdin);
    freopen("10input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    long long val = 1e6;
    while (t--)
    {
        cout << mt() % 100000000 << " " << mt() % 1000000000 << endl;
        cout << "~" << endl;
    }
    return 0;
}

//