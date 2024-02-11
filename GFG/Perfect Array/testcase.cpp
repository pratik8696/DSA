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
    t = 1000;
    cout << t << endl;
    while (t--)
    {
        int N = mt() % 500 + 1;
        cout << N << endl;
        for (int i = 0; i < N; i++)
        {
            cout << mt() % int(pow(10, mt() % 6 + 1)) + 1 << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}