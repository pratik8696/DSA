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
    int maximumItems(int N, int K, vector<int> &Prices)
    {
        sort(Prices.begin(), Prices.end());
        int i = 0, j = 0;
        int answer = 0;

        while (i < Prices.size())
        {
            while (j < Prices.size() && Prices[j] <= Prices[i] + K)
            {
                j += 1;
            }

            answer = max(j - i, answer);

            i += 1;
        }

        return answer;
    }
};

int main()
{
    freopen("100in.txt", "r", stdin);
    freopen("100out.txt", "w", stdout);

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
        int res = obj.maximumItems(N, K, Prices);

        cout << res << endl;
        cout << "~" << endl;
    }
}
