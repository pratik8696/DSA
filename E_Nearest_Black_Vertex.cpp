#include <bits/stdc++.h>
using namespace std;

struct job
{
    int startTime;
    int endTime;
    int jobProfit;
};

bool compare(job a, job b)
{
    return a.endTime < b.endTime;
}

int nonConflictingJob(vector<job> &jobs, int i)
{
    int s = 0;
    int e = i - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (jobs[mid].endTime <= jobs[i].startTime)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

long long int findMaxProfit(vector<int> &start, vector<int> &end, vector<int> &profit)
{
    int n = start.size();
    vector<job> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i].startTime = start[i];
        jobs[i].endTime = end[i];
        jobs[i].jobProfit = profit[i];
    }
    sort(jobs.begin(), jobs.end(), compare);
    vector<long long int> dp(n);
    dp[0] = jobs[0].jobProfit;
    for (int i = 1; i < n; i++)
    {
        long long int excProfit = dp[i - 1];
        long long int incProfit = jobs[i].jobProfit;
        int index = nonConflictingJob(jobs, i);
        if (index != -1)
        {
            incProfit += dp[index];
        }
        dp[i] = max(incProfit, excProfit);
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> start(n), end(n), profit(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> end[i] >> profit[i];
    }
    cout << findMaxProfit(start, end, profit) << endl;
}
