#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// Back-end complete function Template for C++

class Solution
{
public:
    int minimumDifference(int N, int K, vector<int> &Prices)
    {
        int answer = INT_MAX;
        sort(Prices.begin(), Prices.end());

        for (int i = 0; i <= N - K; i++)
        {
            answer = min(answer, Prices[i + K - 1] - Prices[i]);
        }

        return answer;
    }
};

int main()
{
    freopen("10in.txt", "r", stdin);
    freopen("10out.txt", "w", stdout);
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        vector<int> Prices(N);
        Array::input(Prices, N);

        char x;
        cin >> x;

        Solution obj;
        int res = obj.minimumDifference(N, K, Prices);

        cout << res << endl;
        cout << "~" << endl;
    }
}
