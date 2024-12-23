#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<int> &cost,vector<int> &dp,int ind)
    {
        if(ind==0 || ind==1){
            return cost[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = cost[ind] + min(minCost(cost,dp,ind-1),minCost(cost,dp,ind-2));
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
      int n = cost.size();  
      vector<int> dp(n+1,-1);
      return  min(minCost(cost,dp,n-1),minCost(cost,dp,n-2));   
    }
};
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
      int n = cost.size();  
      vector<int> dp(n+1,-1);
      dp[0] = cost[0],dp[1] = cost[1];
      for(int i=2 ;i <n ; i++)
      {
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
      }
      return  min(dp[n-1],dp[n-2]);   
    }
};