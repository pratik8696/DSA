#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("100out.txt", "r", stdin);
    freopen("100in.txt", "w", stdout);
    // #endif
    mt19937 mt;
    srand(time(0));
    int t;
    t = 10;
    cout << t << endl;
    int mod = 1e9;
    while (t--)
    {
        int N = 10000;
        cout << N << " ";

        // for (int i = 0; i < N; i++)
        // {
        //     cout << (mt() % int(pow(10, mt() % 10))) + 1 << " ";
        // }
        // cout << endl;

        vector<ll> arr, brr;

        for (int i = 0; i < N; i++)
        {
            int value = (mt() % int(pow(10, (mt() % 10)))) + 1;
            arr.push_back(value);
            brr.push_back(value);
        }

        sort(begin(arr), end(arr));

        int idx1 = mt() % N;
        int idx2 = mt() % N;

        while (idx1 == idx2)
        {
            idx1 = mt() % N;
            idx2 = mt() % N;
        }

        int i = min(idx1, idx2);
        int j = max(idx1, idx2);

        int value = (arr[j] - arr[i]) + 1;
        cout << value << endl;
        for (auto t : brr)
        {
            cout << t << " ";
        }
        cout << endl;
        // cout << sum << endl;
        cout << "~\n";
    }
    return 0;
}