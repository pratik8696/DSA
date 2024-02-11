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
        int N = (mt() % 30) + 1;
        cout << N << endl;
        for (int i = 0; i < N; i++)
        {
            cout << (mt() % int(pow(10, mt() % 10))) + 1 << " ";
        }
        cout << endl;
        vector<ll> arr;
        ll sum = 0;
        for (int i = 0; i < N; i++)
        {
            arr.push_back((mt() % int(pow(10, mt() % 10))) + 1);
            if (rand() % 4 == 0)
            {
                if (rand() % 2 == 0)
                {
                    sum += arr.back();
                }
            }
        }
        for (auto t : arr)
        {
            cout << t << " ";
        }
        cout << endl;
        cout << sum << endl;
        cout << "~\n";
    }
    return 0;
}