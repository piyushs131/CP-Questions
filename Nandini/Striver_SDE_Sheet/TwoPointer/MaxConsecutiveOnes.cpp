#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
       int n = nums.size();
       int l =0, r=0,zeros=0, ans =0;
       while(l<=r && r<n)
       {
         if(nums[r]==0)
         zeros++;

         if(zeros>k)
         {
            while(nums[l]!=0) l++;
            l++;
            zeros--;
         }
         ans = max(ans,r-l+1);
         r++;
       }
       return ans; 
    }
};