#include <bits/stdc++.h>
using namespace std;

int duplicatecount(string n)
{
    int arrs[26];
    int arrc[26];
    for (int i = 0; i < 26; i++)
    {
        arrs[i] = 0;
        arrc[i] = 0;
    }
    // now iterating through the string which has been entered
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] >= 97 && n[i] <= 122)
        {
            arrs[n[i] - 97]++;
        }
        else if (n[i] >= 65 && n[i] <= 90)
        {
            arrc[n[i] - 65]++;
        }
        else
        {
            cout<<"Plz enter correct alphabets!!!!!!!";
            return 0;
        }
    }
    // for checking the dupliactes found
    for (int i = 0; i < 26; i++)
    {
        if (arrs[i] > 1)
        {
            char a = i + 97;
            cout << a << " = " << arrs[i] << endl;
        }

        if (arrc[i] > 1)
        {
            char a = i + 65;
            cout << a << " = " << arrc[i] << endl;
        }
    }
}

int main()
{
    string n;
    cin >> n;
    duplicatecount(n);
    return 0;
}