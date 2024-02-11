#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int chocolateAverage(int n, vector<int> &Chocolates)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> hsh;
            vector<int> v;
            long long avg = 0, cc = 0;
            for (int j = i; j < n; j++)
            {
                v.push_back(Chocolates[j]);
                hsh[Chocolates[j]]++;
                avg += Chocolates[j];
                cc++;
                long long val = avg / cc;
                if (hsh[val] && cc > 1)
                {
                    count++;
                }
            }
        }
        return count;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        char x;
        cin >> x;
        Solution s;
        cout << s.chocolateAverage(n, arr) << endl;
        cout << "~" << endl;
    }
}