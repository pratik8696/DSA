#include <bits/stdc++.h>
using namespace std;

// Back-end complete function Template for C++
class Solution
{
public:
    int minCostPath(int n, int m, vector<vector<int>> &arr)
    {
        vector<pair<int, int>> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res.push_back({arr[i][j], j});
            }
        }
        sort(begin(res), end(res));
        unordered_map<int, int> hsh;
        // deque<int> dq;
        int i = 0, ans = 1e9;
        for (int j = 0; j < res.size(); j++)
        {
            hsh[res[j].second]++;
            while (hsh.size() == m)
            {
                hsh[res[i].second]--;
                if (hsh[res[i].second] == 0)
                {
                    hsh.erase(res[i].second);
                }
                ans = min(ans, res[j].first - res[i].first);
                i++;
            }
        }
        return ans;
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
        int N;
        int M;
        cin >> N >> M;

        vector<vector<int>> A(N, vector<int>(M));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> A[i][j];
            }
        }

        char x;
        cin >> x;

        Solution obj;
        int res = obj.minCostPath(N, M, A);

        cout << res << endl;
        cout << "~" << endl;
    }
}
