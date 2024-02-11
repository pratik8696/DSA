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
    // int mod = 1e9;
    while (t--)
    {
        int N = 100000;
        cout << N << endl;
        for (int i = 0; i < N; i++)
        {
            cout << (mt() % int(pow(10, mt() % 10))) + 1 << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}