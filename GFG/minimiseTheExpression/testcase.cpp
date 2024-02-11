#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("10000out.txt", "r", stdin);
    freopen("10000input.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 100;
    cout << t << endl;
    while (t--)
    {
        int N = 0;
        while (N < 1000)
        {
            N = mt() % 10001;
        }
        cout << N << endl;
        ll sum = 0;
        for (int i = 1; i < N; i++)
        {
            ll curr = (mt() % 100000) + 1;
            cout << curr << " ";
            sum += curr;
            sum %= ll(N);
        }
        cout << (N - sum == 0 ? N : N - sum) << endl;
        cout << "~\n";
    }
    return 0;
}

//