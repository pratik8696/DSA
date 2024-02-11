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
    map<int, int> hsh;
    hsh[0]++;
    long long val = 1e10;
    while (t--)
    {
        long long a = 1, m = 0;
        while (a > m)
        {
            a = mt() % val;
            m = mt() % val;
        }
        cout << a << " " << m << endl;
        cout << "~" << endl;
    }
    return 0;
}

//