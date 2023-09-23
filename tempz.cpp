#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'MaxEvenNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 * 1. INTEGER ARRAY A
 * 2. INTEGER N
 */

int MaxEvenNumber(vector<int> A, int N)
{
    // Write your code here
}

int MaxEvenNumber(vector<int> A, int N)
{
    int prev = A[0] % 2, count = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (prev != A[i] % 2)
        {
            if (prev == 1)
            {
                ans += (count / 2) * 2;
            }
            else
            {
                ans += count;
            }
            prev = A[i] % 2;
            count = 1;
        }
        else
        {
            count++;
        }
    }
    if (prev == 1)
    {
        ans += (count / 2) * 2;
    }
    else
    {
        ans += count;
    }
    return count;
}

int main()
{

    string A_count_temp;
    getline(cin, A_count_temp);

    int A_count = stoi(ltrim(rtrim(A_count_temp)));

    vector<int> A(A_count);

    for (int i = 0; i < A_count; i++)
    {
        string A_item_temp;
        getline(cin, A_item_temp);

        int A_item = stoi(ltrim(rtrim(A_item_temp)));

        A[i] = A_item;
    }

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = MaxEvenNumber(A, N);

    cout << result;

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}