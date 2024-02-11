#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("100000out.txt", "r", stdin);
    freopen("100000input.txt", "w", stdout);
    // #endif
    srand(time(0));
    int t;
    t = 1;
    cout << t << endl;
    map<pair<int, int>, int> m;
    // int sum = 1e5;
    while (t--)
    {
        int N = 100000;
        cout << N << " ";
        int K = 100000;
        cout << K << endl;
        int a[N];
        for (int i = 0; i < K; i++)
        {
            int a = 0, b = 0;

            while (a == b || m.count({a, b}))
            {
                a = (rand() % N);
                b = (rand() % N);
            }

            cout << a << " " << b << endl;
        }
        cout << "~\n";
    }
    return 0;
}