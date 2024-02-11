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
    int mod = 1e9;
    while (t--)
    {
        int N = 100000;
        cout << N << " ";
        int k = (mt() % int(pow((rand() % 10) + 1, (mt() % 5) + 1))) + 1;
        cout << k << endl;
        // for (int i = 0; i < N; i++)
        // {
        //     cout << (mt() % int(pow(10, mt() % 10))) + 1 << " ";
        // }
        // cout << endl;
        vector<ll> arr;
        // ll sum = 0;
        for (int i = 0; i < N; i++)
        {
            arr.push_back((mt() % mod) + 1);
            // if (rand() % 4 == 0)
            // {
            //     if (rand() % 2 == 0)
            //     {
            //         sum += arr.back();
            //     }
            // }
        }
        for (auto t : arr)
        {
            cout << t << " ";
        }
        cout << endl;
        // cout << sum << endl;
        cout << "~\n";
    }
    return 0;
}