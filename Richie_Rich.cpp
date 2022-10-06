#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int n;
        cin >> n;
        int count = n;
        int totalsum = (n * (n + 1)) / 2;
        while (totalsum % 2 != 0)
        {
            totalsum -= n;
            count--;
        }
        cout << count << endl;
    }
    return 0;
}