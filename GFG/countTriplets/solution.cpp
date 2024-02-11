#include <bits/stdc++.h>
using namespace std;
// Back-end complete function template for C++

class Solution
{
public:
    // Function to count the number of triplets with the given condition.
    int countTriplet(int arr[], int n)
    {
        // Sorting the array in ascending order.
        sort(arr, arr + n);

        // Initializing the count of triplets as 0.
        int ans = 0;

        // Iterating over the array in reverse order.
        for (int i = n - 1; i >= 0; i--)
        {
            // Initializing two pointers, one at the beginning and one at i-1.
            int j = 0;
            int k = i - 1;

            // Using two-pointer approach to find the triplets.
            while (j < k)
            {
                // If the given condition is satisfied, increment the count and move the pointers.
                if (arr[i] == arr[j] + arr[k])
                {
                    ans++;
                    j++;
                    k--;
                }
                // If the sum is less than the target, move the left pointer.
                else if (arr[i] > arr[j] + arr[k])
                    j++;
                // If the sum is greater than the target, move the right pointer.
                else
                    k--;
            }
        }
        // Returning the count of triplets.
        return ans;
    }
};

int main()
{
    freopen("1000input.txt", "r", stdin);
    freopen("1000out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        char x;
        cin >> x;

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";
        cout << "~" << endl;
    }
    return 0;
}
