#include <bits/stdc++.h>
using namespace std;
// Back-end complete function Template for C++
class Solution
{
public:
    vector<long long> geekhotelQueries(vector<long long> arrival, vector<long long> departure, vector<long long> queries)
    {
        int n = arrival.size();
        int q = queries.size();
        map<long long, long long> m;
        long long min_time = 1e18;
        long long max_time = -1e18;
        for (int i = 0; i < n; i++)
        {
            m[arrival[i]]++;
            m[departure[i] + 1]--;
            min_time = min(arrival[i], min_time);
            max_time = max(departure[i], max_time);
        }
        long long curr_count_of_guests = 0;
        for (auto pairs : m)
        {
            auto time = pairs.first;
            auto count = pairs.second;
            curr_count_of_guests += count;
            m[time] = curr_count_of_guests;
        }
        vector<long long> ans;
        for (int i = 0; i < q; i++)
        {
            if (queries[i] < min_time || queries[i] > max_time)
            {
                ans.push_back(0);
                continue;
            }
            auto it = m.upper_bound(queries[i]);
            it--;
            ans.push_back(it->second);
        }
        return ans;
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
        int n, m;
        cin >> n >> m;
        vector<long long int> arrival(n), departure(n), queries(m);

        for (int i = 0; i < n; i++)
            cin >> arrival[i];
        for (int i = 0; i < n; i++)
            cin >> departure[i];
        for (int i = 0; i < m; i++)
            cin >> queries[i];

        char x;
        cin >> x;

        Solution ob;
        vector<long long int> ans = ob.geekhotelQueries(arrival, departure, queries);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;

        cout << "~" << endl;
    }
}