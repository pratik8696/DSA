#include <bits/stdc++.h>
using namespace std;

long long magicalNumber(long long int a, long long int b)
{
    if (a == 0)
    {
        return b;
    }
    return magicalNumber(b % a, a);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a;
        string b;
        cin >> a >> b;
        // reduce b
        long long int temp = 0;
        for (int i = 0; i < b.length(); i++)
        {
            temp = (temp * 10 + b[i] - '0') % a;
        }
        cout << magicalNumber(a, temp) << endl;
    }
    return 0;
}
