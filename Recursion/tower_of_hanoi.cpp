#include <iostream>
using namespace std;
int hanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        static int i = 1;
        hanoi(n - 1, b, a, c);
        cout << "Step " << i++ << " From " << b << " to " << c << " using " << a << endl;
        hanoi(n - 1, a, c, b);
    }
}

int main()
{
    int n;
    cin>>n;
    hanoi(n,1,2,3);
    return 0;
}