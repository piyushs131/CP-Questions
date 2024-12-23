#include <bits/stdc++.h>
using namespace std;
int maxSum(vector<int> &nums,int ind,vector<int> &dp)
{
    if(ind<0) return 0;
    if(ind==0) return nums[0];
    if(dp[ind]!=-1) return dp[ind];

    int f1 = nums[ind]+maxSum(nums,ind-2,dp);
    int f2 = maxSum(nums,ind-1,dp);
    return dp[ind] = max(f1,f2);
} 
int maximumNonAdjacentSum(vector<int> &nums)
{
   vector<int> dp(nums.size()+1,-1); 
   return maxSum(nums,nums.size()-1,dp);
}
