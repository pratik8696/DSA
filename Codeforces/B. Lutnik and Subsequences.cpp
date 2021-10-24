// C++ implementation to find all the
// subsequence whose sum is K

#include <bits/stdc++.h>
using namespace std;

// Utility function to find the subsequences
// whose sum of the element is K
int subsetSumToK(int arr[], int n,
                 int output[][50], int k)
{

    // Base Case
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // Array to store the subsequences
    // which includes the element arr[0]
    int output1[1000][50];

    // Array to store the subsequences
    // which not includes the element arr[0]
    int output2[1000][50];

    // Recursive call to find the subsequences
    // which includes the element arr[0]
    int size1 = subsetSumToK(arr + 1,
                             n - 1, output1, k - arr[0]);

    // Recursive call to find the subsequences
    // which not includes the element arr[0]
    int size2 = subsetSumToK(arr + 1, n - 1,
                             output2, k);

    int i, j;

    // Loop to update the results of the
    // Recursive call of the function
    for (i = 0; i < size1; i++)
    {

        // Incremeing the length of
        // jagged array because it includes
        // the arr[0] element of the array
        output[i][0] = output1[i][0] + 1;

        // In the first column of the jagged
        // array put the arr[0] element
        output[i][1] = arr[0];
    }

    // Loop to update the subsequence
    // in the output array
    for (i = 0; i < size1; i++)
    {
        for (j = 1; j <= output1[i][0]; j++)
        {
            output[i][j + 1] = output1[i][j];
        }
    }

    // Loop to update the subsequences
    // which do not include the arr[0] element
    for (i = 0; i < size2; i++)
    {
        for (j = 0; j <= output2[i][0]; j++)
        {
            output[i + size1][j] = output2[i][j];
        }
    }

    return size1 + size2;
}

// Function to find the subsequences
// whose sum of the element is K
void countSubsequences(int arr[], int n,
                       int output[][50], int k)
{
    int size = subsetSumToK(arr, n, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}

// Driver Code
int main()
{
   
        int output[1000][50];
        int n, sum = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        countSubsequences(arr, n, output, sum - 1);
   
    return 0;
}
