#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-values[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                }
                else
                {
                    profit = max(values[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                }

                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};
long maxProfit(int ind, int buy, long *values, int n, vector<vector<long>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    long profit = 0;
    if (buy)
    {
        profit = max(-values[ind] + maxProfit(ind + 1, 0, values, n, dp), maxProfit(ind + 1, true, values, n, dp));
    }
    else
    {
        profit = max(values[ind] + maxProfit(ind + 1, true, values, n, dp), maxProfit(ind + 1, false, values, n, dp));
    }

    return dp[ind][buy] = profit;
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return maxProfit(0, 1, values, n, dp);
}