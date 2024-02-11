// Initial Template for C++

#include "bits/stdc++.h"
using namespace std;
// Back-end complete function Template for C++

class Solution
{
public:
    int minTime(int n, vector<int> &health)
    {
        return *max_element(health.begin() + 1, health.end());
    }
};

int main()
{
    freopen("10input.txt", "r", stdin);
    freopen("10output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> health(n), power(n);
        for (int i = 0; i < n; i++)
            cin >> health[i];
        Solution ob;
        char x;
        cin >> x;
        int ans = ob.minTime(n, health);
        cout << ans << endl;
        cout << "~" << endl;
    }
}