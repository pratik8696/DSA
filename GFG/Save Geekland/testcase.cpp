#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("10out.txt", "r", stdin);
    freopen("10input.txt", "w", stdout);
    // #endif
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    while (t--)
    {
        int N = 1000;
        cout << N << " ";
        int M = 1000;
        cout << M << endl;
        int p[N], d[M], c[M];
        for (int i = 0; i < N; i++)
        {
            p[i] = (rand() % 1000) + 1;
        }
        for (int i = 0; i < M; i++)
        {
            d[i] = (rand() % 1000) + 1;
            c[i] = (rand() % 1000) + 1;
        }
        for (int i = 0; i < N; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < M; i++)
        {
            cout << d[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < M; i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

//