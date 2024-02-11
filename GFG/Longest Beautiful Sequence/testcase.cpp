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
    while (t--)
    {
        int N = 1000;
        cout << N << " ";
        int ab = (rand() % 10000) + 1;
        int ba = (rand() % 10000) + 1;
        int M = ab * ba;
        if ((mt() % 10) % 3 == 0)
        {
            cout << -M << endl;
        }
        else
        {
            cout << M << endl;
        }
        int p[N];
        for (int i = 0; i < N; i++)
        {
            int a = (mt() % 100) + 1;
            int b = (mt() % 10000000) + 1;
            int c = (mt() % 51);
            if ((i + 1) % 7 == 0)
            {
                p[i] = a * b;
                p[i] *= -1;
            }
            else
            {
                p[i] = a * b;
            }
            if (c == 0)
            {
                p[i] = M * ((rand() % 10) + 1);
            }
        }
        for (int i = 0; i < N; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

//