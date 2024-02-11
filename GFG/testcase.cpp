#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // #endif
    srand(time(0));
    int t;
    t = 100;
    cout << t << endl;
    int sum = 1e5;
    while (t--)
    {
        int N = 1e3;
        // while (sum - N < 0)
        // {
        //     N = rand() % 100000 + 1;
        // }
        // sum-=N;
        cout << N << " ";
        int K = rand() % 1000000 + 1;
        cout << K << endl;
        int a[N];
        for (int i = 0; i < N; i++)
        {
            if (i % 7 == 0)
                a[i] = -(rand() % 10 + 1);
            else
                a[i] = (rand() % 1000 + 1);
            cout << a[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}