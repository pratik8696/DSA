#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        nums[i]=abs(nums[i]);
    }
    sort(nums,nums+n);
    for (int i = 0; i < n; i++)
    {
        nums[i]=pow(nums[i],2);
    }
    for (int i = 0; i < n; i++)
    {
        cout<< nums[i]<<" ";
    }
}