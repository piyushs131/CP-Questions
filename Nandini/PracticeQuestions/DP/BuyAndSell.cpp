#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int n = prices.size();
      int mini = prices[0];
      int ans = INT_MIN;
      for(int i=0 ;i <n ; i++)
      {
         mini = min(mini,prices[i]);
         ans = max(ans,prices[i]-mini);
      }  
      return ans;
    }
};