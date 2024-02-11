#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("1000out.txt", "r", stdin);
    freopen("1000input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    while (t--)
    {
        int N = mt() % 100000 + 1;
        int K = mt() % 1000000000;
        cout << N << " " << K << endl;
        for (int i = 0; i < N; i++)
        {
            cout << mt() % 10000 << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

//