#include <iostream>
#include <vector>
typedef long long ll;
ll digitsum(ll num)
{
    // Function to calculate the sum of digits of a number
    ll sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

ll precomputeDigitSums(ll limit, std::vector<ll> &digitSums)
{
    ll count = 0;

    for (ll i = 1; i < limit; ++i)
    {
        ll digitSum = digitsum(i);
        digitSums[i] = digitSum;
        count += digitSum;
    }

    return count;
}

ll countTripletsOptimized(ll n, const std::vector<ll> &digitSums)
{
    ll count = 0;
    ll digitSumN = digitsum(n);

    // Iterate through possible values of 'a' and check digit sum conditions
    for (ll a = 1; a < n; ++a)
    {
        ll b = n - a;
        ll digitSumA = digitSums[a];
        ll digitSumB = digitSums[b];
        if (digitSumA + digitSumB == digitSumN)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    const ll limit = 100000; // 1e7 + 1
    std::vector<ll> digitSums(limit, 0);

    // Precompute digit sums and get the total sum of digit sums
    ll totalDigitSum = precomputeDigitSums(limit, digitSums);

    // Loop through values of n from 0 to 1e7
    for (ll n_value = 0; n_value <= 100000; ++n_value)
    {
        ll result = totalDigitSum - 2 * digitSums[n_value];
        std::cout << "The number of triplets for n = " << n_value << " is: " << result << std::endl;
    }

    return 0;
}
