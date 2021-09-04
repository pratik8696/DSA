#include <bits/stdc++.h>
using namespace std;

int checkofanagram(string a, string b)
{
    int i = 0;
    int A[26];
    for (int i = 0; i < 26; i++)
    {
        A[i] = 0;
    }
    for (int i = 0; i < a.length(); i++)
    {
        A[a[i] - 97]++;
    }
    for (int i = 0; i < b.length(); i++)
    {
        A[b[i] - 97]--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (A[i] < 0)
        {
            cout << "Not a anagram" << endl;
            return 0;
        }
    }
    cout << "It's a Anagram";
}

int main()
{
    string a, b;
    cin >> a >> b;
    checkofanagram(a, b);
    return 0;
}