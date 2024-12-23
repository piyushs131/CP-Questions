#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i, int j, vector<int> &a, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int maxi = 0;
        for (int ind = i; ind <= j; ind++) {
            int coins = a[i - 1] * a[ind] * a[j + 1] + f(i, ind - 1, a, dp) + f(ind + 1, j, a, dp);
            maxi = max(coins, maxi);
        }
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        
        return f(1, n, nums, dp);
    }
};
