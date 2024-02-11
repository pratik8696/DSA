#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // #ifndef ONLINE_JUDGE
    freopen("1000out.txt", "r", stdin);
    freopen("1000in.txt", "w", stdout);
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
        int N = 50000;
        // cout << N << " ";
        vector<ll> arr;
        unordered_map<int, int> m;
        for (int i = 0; i < N; i++)
        {
            int value = mt() % int(1e9) + 1;
            if (mt() % 5 == 0)
            {
                arr.push_back(-value);
            }
            else
            {
                arr.push_back(value);
            }
            m[arr.back()]++;
        }
        ll value = 0, sum = 0;
        for (auto t : m)
        {
            if (t.second > value)
            {
                value = t.second;
                sum = t.first;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (arr[i] != sum)
            {
                arr.push_back(arr[i]);
            }
        }
        cout << arr.size() << " ";
        cout << sum << endl;
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