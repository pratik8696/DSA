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
    t = 1000;
    cout << t << endl;
    while (t--)
    {
        // n m k x
        /*
        1 <= n <=105
        n < m <=109
        0 < k < m
        1 <= x <= n+1
        */
        int n = (mt() % 1000) + 1;
        int m = (mt() % 1000000000) + 1;
        int k = mt() % m;
        int x = (mt() % (n + 1)) + 1;
        cout << n << " " << m << " " << k << " " << x << endl;
        cout << "~\n";
    }
    return 0;
}

//