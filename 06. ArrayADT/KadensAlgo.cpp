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
    int res=array[0];

    for (int i = 0; i < n; i++)
    {
        currentmax = max(currentmax + array[i], array[i]);
        res=max(currentmax,res);
    }
    cout <<res<< endl;
    // int a[]={1,-2,3,-4,6,-9,5};
    return 0;
}