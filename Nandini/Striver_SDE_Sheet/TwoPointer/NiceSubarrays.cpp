#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int sumLessThanGoal(vector<int> &nums,int goal)
    {
         int n = nums.size(), l=0,r=0,count=0,sum=0;
       if(goal<0) return 0;
       while(r<n)
       {
         sum+= nums[r]%2;
         while(sum>goal)
         {
            sum-=nums[l]%2;
            l++;
         }
         count += (r-l+1);
         r++;
       } 
       return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
       return sumLessThanGoal(nums,k) - sumLessThanGoal(nums,k-1); 
    }
};