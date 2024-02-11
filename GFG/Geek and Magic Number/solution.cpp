#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool magicNumber(int n, vector<int> &arr)
    {
        sort(begin(arr), end(arr));
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                return false;
            }
        }
        int crt_able = 1;
        vector<int> cnt(n);
        for (int mod = 2; mod <= n / 2; mod++)
        {
            fill(begin(cnt), end(cnt), 0);
            for (int i = 1; i <= n; i++)
            {
                cnt[arr[i] % mod]++;
            }
            if (*min_element(begin(cnt), end(cnt)) >= 2)
            {
                crt_able = 0;
            }
        }
        return (crt_able == 1 ? true : false);
    }
};

int main()
{
    freopen("1000input.txt", "r", stdin);
    freopen("1000output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution obj;
        bool res = obj.magicNumber(N,Arr);
        char x;
        cin >> x;
        cout << (res == true ? "Yes" : "No") << endl;
        cout << "~" << endl;
    }
}
