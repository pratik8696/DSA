// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// Back-end complete function Template for C++
class Solution
{
public:
    // Function to check if a number is an Armstrong number.
    string armstrongNumber(int n)
    {
        int sum = 0;  // variable to store the sum of cube of digits
        int temp = n; // variable to store the value of n

        // loop to calculate the sum of cube of digits
        while (temp)
        {
            int last_dig = temp % 10;                // extracting the last digit of temp
            temp /= 10;                              // updating temp to remove the last digit
            sum += (last_dig * last_dig * last_dig); // adding the cube of last digit to sum
        }

        // checking if the sum is equal to the original number
        // and returning "Yes" if true, "No" if false
        if (sum == n)
            return "Yes";
        else
            return "No";
    }
};
int main()
{
    freopen("1000input.txt", "r", stdin);
    freopen("1000output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        char x;
        cin >> x;
        cout << ob.armstrongNumber(n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
