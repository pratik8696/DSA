#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int NewInt(int n, int d)
{
    int count = 0, temp = n, rem, tens = 0;
    while (temp > 0)
    {
        rem = temp % 10;
        temp = temp / 10;
        tens++;
        if (rem == d)
        {
            temp = (rem + 1) * pow(10, tens - 1) + temp * pow(10, tens);
            count = temp - n;
            tens = 0;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        int ans = NewInt(n, d);
        cout << ans << endl;
    }
    return 0;
}