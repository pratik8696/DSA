/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            auto t = nums[i];
            cout << t << " " << m[target - t] << endl;
            
            if (m[target - t])
            {
                return {i, m[target - t]};
            }

            m[t] = i;
        }
        return {};
    }
};
// @lc code=end
