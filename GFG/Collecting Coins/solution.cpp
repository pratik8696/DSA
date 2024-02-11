#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Back-end complete function Template for C++
class Solution
{
public:
    int collectingCoins(int n, vector<vector<int>> &arr)
    {
        int ans = 0;

        unordered_map<int, int> x, y;

        for (int i = 0; i < n; i++)
        {
            x[arr[i][0]]++;
            y[arr[i][1]]++;
            ans = max({ans,
                       x[arr[i][0]],
                       y[arr[i][1]]});
        }

        sort(begin(arr), end(arr));
        vector<int> primary(n), secondary(n);

        for (int i = 0; i < n; i++)
        {
            int X = arr[i][0], Y = arr[i][1], cc = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                int XX = arr[j][0], YY = arr[j][1];
                if (abs(XX - X) == abs(YY - Y) && (XX - X) == (YY - Y))
                {
                    cc = max(cc, primary[j]);
                }
            }
            cc++;
            primary[i] = cc;
            ans = max(ans, cc);
        }

        for (int i = 0; i < n; i++)
        {
            int X = arr[i][0], Y = arr[i][1], cc = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                int XX = arr[j][0], YY = arr[j][1];
                if (abs(XX - X) == abs(YY - Y) && (XX - X) != (YY - Y))
                {
                    cc = max(cc, secondary[j]);
                }
            }
            cc++;
            secondary[i] = cc;
            ans = max(ans, cc);
        }

        return ans;
    }
};

int main()
{
    freopen("7input.txt", "r", stdin);
    freopen("7output.txt", "w", stdout);
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        vector<vector<int>> Coins(N, vector<int>(2));
        Matrix::input(Coins, N, 2);
        char x;
        cin >> x;
        Solution obj;
        int res = obj.collectingCoins(N, Coins);

        cout << res << endl;
        cout << "~" << endl;
    }
}
