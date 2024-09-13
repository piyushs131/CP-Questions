#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
      int ans =0,count=0,n = nums.size();
      for(int bitInd=0 ; bitInd<=31 ; bitInd++)  
      {
        count =0;
        for(int i=0 ;i <n ; i++)
        {
            if(nums[i] & (1<<bitInd))count++;
        }
        if(count%3!=0) ans= ans | (1<<bitInd);
      }
      return ans;
    }
};
class Solution2 {
public:
    int singleNumber(vector<int>& nums) 
    {
       int ones =0,twos=0;
       int n = nums.size();
       for(int i=0 ; i<n ; i++) 
       {
         ones = ((ones^nums[i]) & ~twos);
         twos = ((twos^nums[i]) & ~ones);
       }
       return ones;
    }
};