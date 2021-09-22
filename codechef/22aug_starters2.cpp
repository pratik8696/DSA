#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int lower = pow(10, N - 1);
        int upper = pow(10, N) - 1;
        for (int i = lower; i <= upper; i++)
        {
            if (i % 3 == 0 && i % 9 != 0 && i%2!=0)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}