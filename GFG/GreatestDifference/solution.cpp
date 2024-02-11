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

class Solution
{
public:
    int greatestDifference(int N, vector<int> &Arr)
    {
        int or_value = Arr[0], and_value = Arr[0];
        for (int i = 1; i < N; i++)
        {
            or_value |= Arr[i];
            and_value &= Arr[i];
        }
        return or_value - and_value;
    }
};

int main()
{
    freopen("1000input.txt", "r", stdin);
    freopen("1000output.txt", "w", stdout);
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        int N;
        scanf("%d", &N);
        vector<int> Arr(N);
        Array::input(Arr, N);
        Solution obj;
        int res = obj.greatestDifference(N, Arr);
        char x;
        cin >> x;
        cout << res << endl;
        cout << "~" << endl;
    }
}
