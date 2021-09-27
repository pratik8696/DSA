#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll lcm(int a, int b, int gcd)
{
    return (a * 1ll * b) / gcd;
}

int gcd(int a, int b)
{
    while (b % a != 0)
    {
        int t = a;
        a = b % a;
        b = t;
    }
    return b;
}

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int q, p;
        cin >> q >> p;
        if (q > 1000)
        {
            cout << fixed << setprecision(5) << 0.9 * (q * p) << endl;
        }
        else
        {
            cout << fixed << setprecision(5) << 1.0 * (q * p) << endl;
        }
    }
    return 0;
}