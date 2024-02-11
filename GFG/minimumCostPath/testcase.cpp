#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        int N = mt() % 1000 + 1;
        int M = mt() % 100 + 1;
        cout << N << endl;
        cout << M << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                // {
                cout << mt() % 100000000 + 1 << " ";
                // }
            }
            cout << endl;
        }
        cout << "~\n";
    }
    return 0;
}

//