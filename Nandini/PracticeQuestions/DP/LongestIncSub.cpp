#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int findLongest(vector<int>& nums, int ind, int prev,vector<vector<int> > &dp) {
        if (ind == nums.size())
            return 0;

        if(prev!=-1 && dp[ind][prev+1]!=-1) return dp[ind][prev+1];    

        int ans = 0,p1=0,p4=0;
        if (prev==-1 || nums[prev] < nums[ind]) {
             p1 = 1 + findLongest(nums, ind + 1, ind,dp);
        } 
        p4 = findLongest(nums, ind + 1, prev,dp);
        ans = max(p1,p4);
        return dp[ind][prev+1]=ans;
    }
    int lengthOfLIS(vector<int>& nums) 
    { 
        int n = nums.size();
        vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        return findLongest(nums, 0, -1,dp); 
    }
};