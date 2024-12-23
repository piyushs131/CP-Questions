#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalCoins(vector<int>& coins, int amt, int ind, vector<vector<int> > &dp) 
    {
        if (ind == coins.size()-1) 
        {
            if (amt % coins[ind] == 0)
                return amt / coins[ind];
            return 1e9;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];

        // pick
        int pick = 1e9;
        if (coins[ind] <= amt)
            pick = 1 + totalCoins(coins, amt - coins[ind], ind,dp);

        int notPick = totalCoins(coins, amt, ind + 1,dp);
        return dp[ind][amt] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int> > dp(n+1,vector<int> (amount+1,-1));
        int ans = totalCoins(coins, amount, 0, dp);
        return ans==1e9?-1:ans;
    }
};