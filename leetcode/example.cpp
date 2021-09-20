#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int currentmax = array[0];
    int count = sizeof(array) / sizeof(int);

    for (int i = 0; i < count; i++)
    {
        currentmax = max(currentmax + array[i], array[i]);
    }
    cout << currentmax << endl;
    // int a[]={1,-2,3,-4,6,-9,5};
    return 0;
}