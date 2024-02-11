// Initial Template for C++

#include "bits/stdc++.h"
using namespace std;
// Back-end complete function Template for C++

class Solution
{
public:
    long long time_required(long long health, long long power)
    {
        return (health / power + (health % power != 0));
    }
    int minTime(int n, vector<int> &health, vector<int> &power)
    {
        long long ans = 0;
        stack<pair<pair<long long, long long>, int>> rem;
        for (int i = 1; i < n; i++)
        {
            long long curr_ans = 0;
            while (health[i] > 0 && !rem.empty())
            {
                pair<pair<long long, long long>, int> curr = rem.top();
                rem.pop();
                long long start = curr.first.first;
                long long end = curr.first.second;
                int index = curr.second;
                long long curr_time = end - start + 1;
                long long req_time = time_required(health[i], power[index]);
                if (req_time < curr_time)
                {
                    curr_ans += req_time;
                    health[i] -= req_time * power[index];
                    rem.push({{start + req_time, end}, index});
                }
                else
                {
                    curr_ans += curr_time;
                    health[i] -= curr_time * power[index];
                }
            }
            if (health[i] > 0)
            {
                long long req_time = time_required(health[i], power[0]);
                health[i] -= req_time * power[0];
                curr_ans += req_time;
                ans += req_time;
            }
            rem.push({{1, curr_ans}, i});
        }
        return (int)ans;
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
        vector<int> health(n), power(n);
        for (int i = 0; i < n; i++)
            cin >> health[i];
        for (int i = 0; i < n; i++)
            cin >> power[i];

        char x;
        cin >> x;
        
        Solution ob;
        int ans = ob.minTime(n, health, power);
        cout << ans << endl;
        cout << "~" << endl;
    }
}