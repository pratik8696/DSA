#include <bits/stdc++.h>
using namespace std;
// Back-end complete function Template for C++
class Solution
{
public:
    string st;

    // Function to print the parenthesis of matrix chain multiplication
    void printParenthesis(int i, int j, int n, int *bracket, char &name)
    {
        // If i and j are equal, it means only one matrix is remaining
        if (i == j)
        {
            st += name; // add the name of matrix to the string
            name++;     // increment the name for the next matrix
            return;
        }
        st += '(';                                                           // add '(' to the string
        printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);     // recursively print the parenthesis for the left side of the split
        printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name); // recursively print the parenthesis for the right side of the split
        st += ')';                                                           // add ')' to the string
    }

    // Function to calculate the minimum number of operations needed to multiply the matrices
    string matrixChainOrder(int p[], int n)
    {
        int m[n][n];       // create a 2D array to store the minimum number of operations
        int bracket[n][n]; // create a 2D array to store the split position for each matrix multiplication
        for (int i = 1; i < n; i++)
            m[i][i] = 0; // initialize the diagonal elements to 0
        for (int L = 2; L < n; L++)
        { // iterate over the lengths of the sequences
            for (int i = 1; i < n - L + 1; i++)
            {                      // iterate over the starting indices of the sequences
                int j = i + L - 1; // calculate the ending index of the sequence
                m[i][j] = INT_MAX; // set the minimum number of operations to a large value at first
                for (int k = i; k <= j - 1; k++)
                {                                                           // iterate over possible split positions
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; // calculate the number of operations needed for this split
                    if (q < m[i][j])
                    { // if this split has less operations than the current minimum, update the values
                        m[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        char name = 'A';                                     // initialize the name of the matrices
        printParenthesis(1, n - 1, n, (int *)bracket, name); // call the function to print the parenthesis
        return st;                                           // return the string containing the parenthesis
    }
};

int get(int p[], int n)
{
    int m[n][n], ans = 1e9;
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            m[i][i + L - 1] = INT_MAX;
            for (int k = i; k <= i + L - 2; k++)
            {
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i - 1] * p[k] * p[i + L - 1];
                if (q < m[i][i + L - 1])
                {
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int find(string s, int p[])
{
    vector<pair<int, int>> arr;
    int ans = 0;
    for (auto t : s)
    {
        if (t == '(')
        {
            arr.push_back({-1, -1});
        }
        else if (t == ')')
        {
            pair<int, int> b = arr.back();
            arr.pop_back();
            pair<int, int> a = arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first, b.second});
            ans += a.first * a.second * b.second;
        }
        else
        {
            arr.push_back({p[int(t - 'A')], p[int(t - 'A') + 1]});
        }
    }
    return ans;
}

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
        int p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        char x;
        cin >> x;
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if (find(result, p) == get(p, n))
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}