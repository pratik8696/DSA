#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("10out.txt", "r", stdin);
    freopen("10input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    map<int, int> hsh;
    hsh[0]++;
    while (t--)
    {
        int value = 0;
        while (hsh.count(value))
        {
            value = mt() % 10000;
        }
        hsh[value]++;
        cout << value << endl;
        cout << "~\n";
    }
    return 0;
}

//