#include <bits/stdc++.h>
using namespace std;

// Back-end complete function Template for C++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

class Solution
{
public:
    int geekStudentPairing(int n, vector<vector<int>> &a, vector<vector<int>> &b)
    {
        vector<pair<int, int>> res1, res2;
        for (auto t : a)
        {
            res1.push_back({t[0], t[1]});
        }
        for (auto t : b)
        {
            res2.push_back({t[0], t[1]});
        }
        sort(begin(res1), end(res1), compare);
        sort(begin(res2), end(res2), compare);
        int i = 0, cc = 0;
        pbds s;
        for (int j = 0; j < n; j++)
        {
            while (i < n && res1[i].first < res2[j].first)
            {
                s.insert(res1[i++].second);
            }
            auto it = s.upper_bound(res2[j].second);
            if (s.size() && it != s.begin())
            {
                it--;
                s.erase(it);
                cc++;
            }
        }
        return cc;
    }
};

int main()
{
    freopen("1000input.txt", "r", stdin);
    freopen("1000output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;
        vector<vector<int>> a, b;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            a.push_back({x, y});
        }
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            b.push_back({x, y});
        }

        char x;
        cin >> x;

        Solution s;
        cout << s.geekStudentPairing(n, a, b) << endl;

        cout << "~" << endl;
    }
    return 0;
}
