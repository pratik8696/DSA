#include <bits/stdc++.h>
using namespace std;

void lastCandy(vector<int> candies, int k, int index)
{
    if (candies.size() == 2)
    {
        cout << candies[0] << " " << candies[1] << endl;
        return;
    }
    index = ((index + k) % candies.size());
    candies.erase(candies.begin() + index);
    lastCandy(candies, k, index);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> candies;
        for (int i = 1; i <= n; i++)
        {
            candies.push_back(i);
        }
        cout << n << " --> ";
        lastCandy(candies, 1, 0);
        cout<<endl;
    }
    return 0;
}