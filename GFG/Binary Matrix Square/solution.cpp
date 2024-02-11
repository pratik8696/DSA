// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Back-end complete function Template for C++

class Solution
{
public:
    // Function to find the maximum size of square submatrix with all 1s.
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // Initialize a 2D array to store the sizes of the square submatrices.
        int sub[n][m], maxsize = 0;

        // Initialize the first row of the submatrix array and update the maximum size.
        for (int i = 0; i < m; i++)
        {
            sub[0][i] = mat[0][i];
            maxsize = max(maxsize, sub[0][i]);
        }

        // Initialize the first column of the submatrix array and update the maximum size.
        for (int i = 0; i < n; i++)
        {
            sub[i][0] = mat[i][0];
            maxsize = max(maxsize, sub[i][0]);
        }

        // Base on the elements of the input matrix, calculate the size of the square submatrices
        // and update the maximum size.
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][j] == 1)
                    sub[i][j] = min(sub[i - 1][j - 1],
                                    min(sub[i][j - 1], sub[i - 1][j])) +
                                1;
                else
                    sub[i][j] = 0;
                maxsize = max(maxsize, sub[i][j]);
            }
        }

        // Return the maximum size of the square submatrix.
        return maxsize;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        char x;
        cin >> x;
        cout << ob.maxSquare(n, m, mat) << "\n";
        cout << "~" << endl;
    }
    return 0;
}