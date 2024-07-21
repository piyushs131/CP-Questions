#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) 
    {
       long long ans =0;
       int n = nums.size();
       int i=0;
       while(i<n)
       {
         if(nums[i]<target[i])
         {
            int j= i;
            int ct =0;
            while(j<n && nums[j]<target[j])
            {
                nums[j]+=1;
                j++;
            }
            ans++;
         }
         else if(nums[i]>target[i])
         {
            int j= i;
            while(j<n && nums[j]>target[j])
            {
                nums[j]-=1;
                j++;
            }
            ans++;
         }
         else i++;

         
       }

       return ans; 
    }
};