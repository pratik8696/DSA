#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("1output.txt", "r", stdin);
    freopen("1input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    while (t--)
    {
        int N = mt() % 10 + 1;
        cout << N << endl;
        for (int i = 0; i < N; i++)
        {
            cout << mt() % 30 + 1 << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}