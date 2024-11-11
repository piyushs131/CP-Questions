#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) 
    {
       int n = nums.size();
       vector<int> inc(n,1);
       for(int i=1 ;i <n ; i++)
       {
         if(nums[i]>nums[i-1])
         inc[i] = inc[i-1]+1;
       } 
       int prevInd,i,ans=0;
       for(i=n-1 ; i>=0 ;)
       {
         ans = max(ans,inc[i]/2);
         prevInd = i-inc[i];
         if(prevInd>=0) ans = max(ans,min(inc[i],inc[prevInd]));
         i=prevInd;
       }
       return ans;
    }
};