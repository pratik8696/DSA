#include <stdio.h>

void solve()
{
    long long int n, sum = 0;
    scanf("%lld",&n);
    if (n == 1 || n == 2)
    {
        printf("%lld\n",1);
        return;
    }
    else if (n > 2)
    {
        sum = ((n-2) * (n -1)) + 1;
        printf("%lld\n",sum);
        return;
    }
}
int main()
{
    long long int t;
    scanf("%lld",&t);
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}