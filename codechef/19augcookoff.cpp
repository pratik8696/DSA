#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        if (N % 2 == 0 && N % 4 == 0)
        {
            cout << "NO"<<endl;
        }
        if (N % 2 == 0 && N % 4 != 0)
        {
            cout << "YES"<<endl;
        }
    }
    return 0;
}