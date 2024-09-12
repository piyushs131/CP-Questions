#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0; 
        if (dp[i][j] != -1) return dp[i][j];

        int pick_start = nums[i] - f(i + 1, j, nums, dp); 
        int pick_end = nums[j] - f(i, j - 1, nums, dp);   
        return dp[i][j] = max(pick_start, pick_end);
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n - 1, nums, dp) >= 0;
    }
};
