#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("10out.txt", "r", stdin);
    freopen("10in.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    // int mod = 1e9;
    // 2^N * log(2^N)
    while (t--)
    {
        int N = 10000;
        int M = mt() % 1000000;
        cout << N << " " << M << endl;
        for (int i = 0; i < N; i++)
        {
            cout << mt() % 100000 << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}