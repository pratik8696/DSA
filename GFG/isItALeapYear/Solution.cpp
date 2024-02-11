#include <bits/stdc++.h>
using namespace std;
// Position this line where user code will be pasted.

class Solution
{
public:
    int isLeap(int N)
    {
        if (N % 100 == 0)
        {
            if (N % 400 == 0)
            {
                return 1;
            }
            else
                return 0;
        }
        else if (N % 4 == 0)
            return 1;
        else
            return 0;
    }
};

int main()
{
    freopen("1input.txt", "r", stdin);
    freopen("1output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        char x;
        cin >> x;
        Solution ob;
        cout << ob.isLeap(N) << endl;
        cout << "~" << endl;
    }
    return 0;
}