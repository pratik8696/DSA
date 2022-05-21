#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Maximum : public unary_function<int, void>
{ // LINE-1
    int count;
    int sum;
    Maximum() : count(0), sum(0) {} // LINE-2
    void operator()(int x)
    {
        sum += x;
        ++count;
    } // LINE-3
};
int main()
{
    vector<int> v;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    Maximum m = for_each(v.begin(), v.end(), Maximum());
    cout << "avg = " << (double)m.sum / m.count;
    return 0;
}