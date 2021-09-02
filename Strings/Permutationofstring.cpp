#include <bits/stdc++.h>
using namespace std;

int stringpermutation(string n, int k, string r)
{
    static int A[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // static string r;
    int i;
    if (n[k] == '\0')
    {
        r[k] = '\0';
        cout << r;
        cout << endl;
    }

    else
    {
        for (i = 0; n[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                r[i] = n[i];
                A[i] = 1;
                stringpermutation(n, k + 1, r);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    string n;
    string answer;
    cin >> n;
    int k = 0;
    stringpermutation(n, k, answer);
    return 0;
}
