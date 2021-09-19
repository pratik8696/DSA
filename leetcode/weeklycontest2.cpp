#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {6, 8, 3, 7, 8, 9, 4, 8};
    int x = nums.size() - 2;
    int flag1 = 1, flag2 = 1, flag3 = 1;
    vector<int> results;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] >= nums[i])
            {
                flag1 = 0;
            }
        }
        for (int k = i + 1; k <= nums.size() - 1; k++)
        {
            if (nums[k] <= nums[i])
            {
                flag2 = 0;
            }
        }

        if (nums[i - 1] >= nums[i] || nums[i] >= nums[i + 1])
        {
            flag3 = 0;
        }

        cout << flag1 << " " << flag2 << " " << flag3 << endl;

        if (flag1 == 1 && flag2 == 1)
        {
            cout << 2 << endl;
            results.push_back(2);
        }
        else if (flag3 == 1)
        {
            cout << 1 << endl;
            results.push_back(1);
        }
        else
        {
            cout << 0 << endl;
            results.push_back(0);
        }
    }
    int res = INT_MIN;
    for (int i = 0; i <= results.size() - 1; i++)
    {
        res = max(results[i], res);
    }
    cout << res;
    return 0;
}