#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimiseExpression(vector<int> &A, int N)
    {
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
        }
        return sum / N;
    }
};

int main()
{
    freopen("10000input.txt", "r", stdin);
    freopen("10000output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        char x;
        cin >> x;

        Solution ob;
        long long int ans = ob.minimiseExpression(A, N);

        cout << ans << endl;
        cout << "~" << endl;
    }
}