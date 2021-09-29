#include <iostream>
using namespace std;

int main()
{
    int n=8;
    int arr[n] = {1, 2, 3, 4, 6, 7, 8, 9};
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    cout<<sum<<endl;
    int x = s - sum;
    cout << x << endl;
    return 0;
}
