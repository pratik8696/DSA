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
    // int mod = 1e9;
    while (t--)
    {
        int N = 1000;
        cout << N << endl;
        for (int i = 0; i < N; i++)
        {
            cout << (mt() % int(pow(10, mt() % 10))) + 1 << " ";
        }
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            cout << (mt() % int(pow(10, mt() % 10))) + 1 << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}